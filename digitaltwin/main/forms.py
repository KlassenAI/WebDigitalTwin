from django import forms


class SettingsForm(forms.Form):
    name = forms.CharField(label="Имя", required=True, help_text="Имя модели")
    path = forms.CharField(label="Путь", required=True, help_text="Путь к модели")
    time = forms.IntegerField(label="Время", required=True, help_text="Время симуляции в сек")
    stepSize = forms.IntegerField(label="Шаг", required=True, help_text="Шаг измерения в сек")
    date = forms.IntegerField(label="Дата", required=True, help_text="Дата начала в мс")
