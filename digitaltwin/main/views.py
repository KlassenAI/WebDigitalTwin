from django.shortcuts import render
from django.contrib import messages
from .forms import SettingsForm
from OMPython import ModelicaSystem
from influxdb import InfluxDBClient
import DyMat as dm
import numpy as np
import pandas as pd
import threading
import re
import csv

simulation_time = "simulationTime"
loop = False
first = False


# симуляция моделики
def simulate_modelica(model_path: str, model_name: str, params: list):
    # создаем моделику для симуляции
    mod = ModelicaSystem(model_path, model_name, params)
    mod.buildModel()
    # устанавливаем параметры симуляции из файла parameters.txt
    mod.setSimulationOptions(params)
    # симуляция моделики и возврат времени начала симуляции
    mod.simulate(resultfile=model_name + ".mat")


# чтение параметров интеграции из текстового файла
def read_parameters(file_name: str):
    ls = list()
    with open(file_name, "r") as f:
        for line in f.readlines():
            ls.append(line.strip())
    return ls


# запись параметров в текстовый файл
def write_params(file_name: str, *params: str):
    with open(file_name, "w") as f:
        for p in params:
            f.write(p + "\n")


# заполнение пустых данных словаря предыдущими непустыми значениями
def filling_missing_data(res: dict, max_count: int):
    for var in res:
        if len(res[var]) != max_count:
            sup_mas = []
            while len(res[var]) + len(sup_mas) != max_count:
                sup_mas.append(res[var][-1])
            res[var] = np.concatenate((res[var], sup_mas))
    return res


# создание конструктора для поиска элементов
def parameter_pattern(*parameters: str):
    pattern = "\.("
    for p in parameters:
        pattern += p
        if not parameters.index(p) == len(parameters) - 1:
            pattern += "|"
    pattern += ")$"
    return pattern


# подсчет скорости воздуха
def count_flow_rate(res: dict, mass_flow: float, density: float, section: float):
    ls = list()
    for i in range(0, len(res[simulation_time])):
        ls.append(res[mass_flow][i] * res[density][i] / res[section][i])
    return ls


# подсчет скорости воздуха в словаре
def count_flow_rates(res: dict, fields: list):

    # необходимые параметры для подсчета скорости воздуха
    dens_par = "d"
    mass_flow_par = "m_flow"
    sect_par = "crossArea"

    # создаем словарь для данных температуры, массового потока, поперечного сечения и скорости воздуха
    dc = dict()
    dc[simulation_time] = res[simulation_time]

    # списки параметров необходимых данных
    d_fields = list()
    m_fields = list()
    s_fields = list()

    # поиск необходимых параметров
    for var in fields:
        if re.search(parameter_pattern(dens_par), var):
            d_fields.append(var)
        if re.search(parameter_pattern(mass_flow_par), var):
            m_fields.append(var)
        if re.search(parameter_pattern(sect_par), var):
            s_fields.append(var)

    # получение списка имен элементов, для которых можно получить скорость воздуха
    names = list()
    for s_field in s_fields:
        names.append(s_field.split(".")[0])

    # получение скорости воздуха и добавление данных в словарь
    for name in names:
        for d_field in d_fields:
            if name == d_field.split(".")[0]:
                for m_field in m_fields:
                    if name == m_field.split(".")[0]:
                        var_name = name + ".flow_rate" + "(" + \
                                   m_field.replace(name + ".", "") + "*" + \
                                   d_field.replace(name + ".", "") + "/" + \
                                   s_fields[names.index(name)].replace(name + ".", "") + ")"
                        dc[var_name] = count_flow_rate(res, m_field, d_field, s_fields[names.index(name)])

    return dc


def simulation():

    global loop

    # параметры для фильтрации получаемых данных
    dens_par = "d"
    mass_flow_par = "m_flow"
    press_par = "p"
    sect_par = "crossArea"
    temp_par = "T"

    # получение параметров модели и симуляции
    model_params = read_parameters("model_params.txt")
    sim_params = read_parameters("sim_params.txt")

    # имя текущей модели и путь к ней, а также измерение модели
    model_name = model_params[0]
    model_path = model_params[1]

    # время начала симуляции в миллисекундах
    timestamp = int(sim_params[-1].strip('date='))
    # интервал в секундах
    interval = int(sim_params[0].strip('stopTime='))

    while loop:
        # проводим симуляцию моделики и создаем файл данных моделики с расширением .mat
        simulate_modelica(model_path, model_name, sim_params)

        if not loop:
            return

        # получаем данные и имена данных из файла
        my_file = dm.DyMatFile(model_name + ".mat")
        data = my_file.names()
        var_names = list()
        for var in data:
            var_names.append(var)

        # время симуляции
        res = dict()
        res[simulation_time] = my_file.abscissa(var_names[0], valuesOnly=True)

        # добавление к времени симуляции начало симуляции
        for var in res:
            res[var] *= 1000
            for i in range(0, len(res[var])):
                res[var][i] = res[var][i] + timestamp

        # отбираем необходимые данные
        fields = [simulation_time]
        for var in data:
            if re.search(parameter_pattern(mass_flow_par, dens_par, sect_par, temp_par, press_par), var):
                fields.append(var)

        # заполнение словаря данными
        max_count = -1
        for varName in var_names:
            if varName in fields:
                res[varName] = my_file.data(varName)
                if len(res[varName]) > max_count:
                    max_count = len(res[varName])

        # заполняем пустые значения
        res = filling_missing_data(res, max_count)

        # подсчитываем скорость воздуха в отдельном словаре
        res2 = count_flow_rates(res, fields)
        for var in res2:
            res[var] = res2[var]

        # сохраняем данные в csv файлах и в InfluxDB
        pd.DataFrame(res).to_csv(model_name + '.csv', index=False, sep=';')

        if not loop:
            return

        # сохраняем данные в базу данных
        influx(model_name)

        if not loop:
            return

        # обновление временной метки
        timestamp += interval * 1000


# проверка на вещественное число
def isfloat(value):
    try:
        float(value)
        return True
    except ValueError:
        return False


# заполнение данными
def all_data(column_names, row):
    fields = {}
    for value in column_names:
        value_buf = 0
        if value in row:
            value_buf = float(row[value]) if isfloat(row[value]) else row[value]
        fields[value] = value_buf
    return fields


def influx(model_name: str):

    # переменные для взаймодействия с базой данных
    db_host = "localhost"
    db_port = 8086
    db_name = "DigitalTwinDB"
    measurement = "DigitalTwin"

    # подключение к InfluxDB
    client = InfluxDBClient(db_host, db_port)

    # создаем новую базу данных и переключаемся на нее
    client.create_database(db_name)
    client.switch_database(db_name)

    # читаем данные из файла csv
    file_path = model_name + '.csv'
    with open(file_path) as fp:
        reader = csv.DictReader(fp, delimiter=";")
        columns_names = reader.fieldnames
        data_read = [row for row in reader]

    # работа с данными для записи в базу данных
    data_to_write = []
    count = 0
    for row in data_read:
        # подсчет количества прочитанных элементов
        count += 1

        # временная метка по времени симуляции
        timestamp = int(float(row[simulation_time]) * 1000000)

        # проверка режима вывода данных
        fields_values = all_data(columns_names, row)

        # запрос для загрузки в базу в json формате
        data = {"measurement": measurement, "time": timestamp,
                "fields": fields_values}
        data_to_write.append(data)

        # загрузка данных постепенно
        if len(data_to_write) % 100 == 0:
            response = client.write_points(data_to_write)
            print("Количество прочитанных данных: ", count)
            print("Количество загруженных данных: ", len(data_to_write))
            if not response:
                print("Произошла ошибка во время загрузки данных")
                exit(1)
            print("Данные успешно загружены")

            data_to_write = []

    # отправка запроса в базу данных и вывод информации
    if len(data_to_write) > 0:
        response = client.write_points(data_to_write)
        print("Количество прочитанных данных: ", count)
        print("Количество загруженных данных: ", len(data_to_write))
        if not response:
            print("Произошла ошибка во время загрузки данных")
            exit(1)
        print("Данные успешно загружены")


def main(request):
    global loop, first
    if first:
        if loop:
            messages.info(request, "Интеграция запущена")
            data = {"button": "Стоп"}
        else:
            messages.info(request, "Интеграция завершена")
            data = {"button": "Запуск"}
    else:
        data = {"button": "Запуск"}
    return render(request, 'main/main.html', context=data)


def settings(request):
    global loop
    if request.method == "POST":
        settings_form = SettingsForm(request.POST)
        if settings_form.is_valid():
            name = request.POST.get("name")
            path = request.POST.get("path")
            write_params("model_params.txt", name, path)
            stopTime = "stopTime=" + request.POST.get("time")
            stepSize = "stepSize=" + request.POST.get("stepSize")
            date = "date=" + request.POST.get("date")
            write_params("sim_params.txt", stopTime, stepSize, date)
            settings_form = SettingsForm(initial={'name': name,
                                                  'path': path,
                                                  'time': stopTime.lstrip('stopTime='),
                                                  'stepSize': stepSize.lstrip('stepSize='),
                                                  'date': date.lstrip('date=')})
            data = {"form": settings_form}
            messages.success(request, "Настройки успешно сохранены")
            if loop:
                loop = False
            return render(request, 'main/settings.html', context=data)
        else:
            model_params = read_parameters("model_params.txt")
            sim_params = read_parameters("sim_params.txt")
            settings_form = SettingsForm(initial={'name': model_params[0],
                                                  'path': model_params[1],
                                                  'time': sim_params[0].lstrip('stopTime='),
                                                  'stepSize': sim_params[1].lstrip('stepSize='),
                                                  'date': sim_params[2].lstrip('date=')})
            data = {"form": settings_form}
            messages.error(request, "Данные не были сохранены, введите корректные данные")
            return render(request, 'main/settings.html', context=data)
    else:
        model_params = read_parameters("model_params.txt")
        sim_params = read_parameters("sim_params.txt")
        settings_form = SettingsForm(initial={'name': model_params[0],
                                              'path': model_params[1],
                                              'time': sim_params[0].lstrip('stopTime='),
                                              'stepSize': sim_params[1].lstrip('stepSize='),
                                              'date': sim_params[2].lstrip('date=')})
        data = {"form": settings_form}
        return render(request, 'main/settings.html', context=data)


def integration(request):
    global loop, first
    first = True
    if not loop:
        loop = True
        thread = threading.Thread(target=simulation)
        thread.start()
        messages.info(request, "Интеграция запущена")
        data = {"button": "Стоп"}
    else:
        loop = False
        messages.info(request, "Интеграция завершена")
        data = {"button": "Запуск"}
    return render(request, 'main/main.html', context=data)
