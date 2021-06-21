#if defined(__cplusplus)
  extern "C" {
#endif
  int MinVen6_mayer(DATA* data, modelica_real** res, short*);
  int MinVen6_lagrange(DATA* data, modelica_real** res, short *, short *);
  int MinVen6_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int MinVen6_setInputData(DATA *data, const modelica_boolean file);
  int MinVen6_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif