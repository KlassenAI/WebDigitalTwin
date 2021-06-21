/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "MinVen6_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void MinVen6_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *MinVen6_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"time < control.startTime"};
  static const int occurEqs0[] = {1,4686};
  static const int *occurEqs[] = {occurEqs0};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */

int MinVen6_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  
  TRACE_POP
  return 0;
}

int MinVen6_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  modelica_boolean tmp0;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  tmp0 = LessZC(data->localData[0]->timeValue, data->simulationInfo->realParameter[2] /* control.startTime PARAM */, data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp0) ? 1 : -1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *MinVen6_relationDescription(int i)
{
  const char *res[] = {"time < control.startTime"};
  return res[i];
}

int MinVen6_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  modelica_boolean tmp1;
  
  if(evalforZeroCross) {
    tmp1 = LessZC(data->localData[0]->timeValue, data->simulationInfo->realParameter[2] /* control.startTime PARAM */, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp1;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->timeValue < data->simulationInfo->realParameter[2] /* control.startTime PARAM */);
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

