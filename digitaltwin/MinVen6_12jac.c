/* Jacobians 5 */
#include "MinVen6_model.h"
#include "MinVen6_12jac.h"
int MinVen6_functionJacF_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int MinVen6_functionJacD_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int MinVen6_functionJacC_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int MinVen6_functionJacB_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

OMC_DISABLE_OPT
int MinVen6_functionJacA_constantEqns(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = MinVen6_INDEX_JAC_A;
  
  
  TRACE_POP
  return 0;
}

int MinVen6_functionJacA_column(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = MinVen6_INDEX_JAC_A;
  TRACE_POP
  return 0;
}

int MinVen6_initialAnalyticJacobianF(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int MinVen6_initialAnalyticJacobianD(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int MinVen6_initialAnalyticJacobianC(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int MinVen6_initialAnalyticJacobianB(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
OMC_DISABLE_OPT
int MinVen6_initialAnalyticJacobianA(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  const int colPtrIndex[1+105] = {0,12,12,12,12,15,12,12,12,12,15,20,5,8,9,9,9,9,9,9,9,13,10,5,8,9,9,9,9,9,9,9,13,10,8,9,9,9,9,9,9,9,13,5,8,9,9,9,9,9,9,9,11,8,5,8,9,9,9,9,9,9,9,11,8,8,9,9,9,9,9,9,9,11,8,11,9,9,9,9,9,9,9,9,6,8,11,9,9,9,9,9,9,9,9,6,11,9,9,9,9,9,9,9,9,6};
  const int rowIndex[983] = {0,1,2,3,4,6,8,10,21,32,73,84,0,1,2,3,4,6,8,10,21,32,73,84,0,1,2,3,4,6,8,10,21,32,73,84,0,1,2,3,4,6,8,10,21,32,73,84,0,1,2,3,4,6,8,10,21,32,73,74,84,85,95,0,2,5,6,7,8,9,10,21,32,52,63,0,2,5,6,7,8,9,10,21,32,52,63,0,2,5,6,7,8,9,10,21,32,52,63,0,2,5,6,7,8,9,10,21,32,52,63,0,2,5,6,7,8,9,10,21,32,51,52,62,63,72,0,1,2,3,4,5,6,7,8,9,10,20,21,31,32,41,52,63,73,84,11,12,22,23,33,11,12,13,22,23,24,33,34,12,13,14,23,24,25,33,34,35,13,14,15,24,25,26,34,35,36,14,15,16,25,26,27,35,36,37,15,16,17,26,27,28,36,37,38,16,17,18,27,28,29,37,38,39,17,18,19,28,29,30,38,39,40,18,19,20,29,30,31,39,40,41,0,2,6,8,10,19,20,21,30,31,32,40,41,0,2,6,8,10,20,21,31,32,41,11,12,22,23,33,11,12,13,22,23,24,33,34,12,13,14,23,24,25,33,34,35,13,14,15,24,25,26,34,35,36,14,15,16,25,26,27,35,36,37,15,16,17,26,27,28,36,37,38,16,17,18,27,28,29,37,38,39,17,18,19,28,29,30,38,39,40,18,19,20,29,30,31,39,40,41,0,2,6,8,10,19,20,21,30,31,32,40,41,0,2,6,8,10,20,21,31,32,41,11,12,13,22,23,24,33,34,12,13,14,23,24,25,33,34,35,13,14,15,24,25,26,34,35,36,14,15,16,25,26,27,35,36,37,15,16,17,26,27,28,36,37,38,16,17,18,27,28,29,37,38,39,17,18,19,28,29,30,38,39,40,18,19,20,29,30,31,39,40,41,0,2,6,8,10,19,20,21,30,31,32,40,41,42,43,53,54,64,42,43,44,53,54,55,64,65,43,44,45,54,55,56,64,65,66,44,45,46,55,56,57,65,66,67,45,46,47,56,57,58,66,67,68,46,47,48,57,58,59,67,68,69,47,48,49,58,59,60,68,69,70,48,49,50,59,60,61,69,70,71,49,50,51,60,61,62,70,71,72,5,7,9,50,51,52,61,62,63,71,72,5,7,9,51,52,62,63,72,42,43,53,54,64,42,43,44,53,54,55,64,65,43,44,45,54,55,56,64,65,66,44,45,46,55,56,57,65,66,67,45,46,47,56,57,58,66,67,68,46,47,48,57,58,59,67,68,69,47,48,49,58,59,60,68,69,70,48,49,50,59,60,61,69,70,71,49,50,51,60,61,62,70,71,72,5,7,9,50,51,52,61,62,63,71,72,5,7,9,51,52,62,63,72,42,43,44,53,54,55,64,65,43,44,45,54,55,56,64,65,66,44,45,46,55,56,57,65,66,67,45,46,47,56,57,58,66,67,68,46,47,48,57,58,59,67,68,69,47,48,49,58,59,60,68,69,70,48,49,50,59,60,61,69,70,71,49,50,51,60,61,62,70,71,72,5,7,9,50,51,52,61,62,63,71,72,1,3,4,73,74,84,85,95,1,3,4,73,74,75,84,85,86,95,96,74,75,76,85,86,87,95,96,97,75,76,77,86,87,88,96,97,98,76,77,78,87,88,89,97,98,99,77,78,79,88,89,90,98,99,100,78,79,80,89,90,91,99,100,101,79,80,81,90,91,92,100,101,102,80,81,82,91,92,93,101,102,103,81,82,83,92,93,94,102,103,104,82,83,93,94,103,104,1,3,4,73,74,84,85,95,1,3,4,73,74,75,84,85,86,95,96,74,75,76,85,86,87,95,96,97,75,76,77,86,87,88,96,97,98,76,77,78,87,88,89,97,98,99,77,78,79,88,89,90,98,99,100,78,79,80,89,90,91,99,100,101,79,80,81,90,91,92,100,101,102,80,81,82,91,92,93,101,102,103,81,82,83,92,93,94,102,103,104,82,83,93,94,103,104,1,3,4,73,74,75,84,85,86,95,96,74,75,76,85,86,87,95,96,97,75,76,77,86,87,88,96,97,98,76,77,78,87,88,89,97,98,99,77,78,79,88,89,90,98,99,100,78,79,80,89,90,91,99,100,101,79,80,81,90,91,92,100,101,102,80,81,82,91,92,93,101,102,103,81,82,83,92,93,94,102,103,104,82,83,93,94,103,104};
  int i = 0;
  
  jacobian->sizeCols = 105;
  jacobian->sizeRows = 105;
  jacobian->sizeTmpVars = 0;
  jacobian->seedVars = (modelica_real*) calloc(105,sizeof(modelica_real));
  jacobian->resultVars = (modelica_real*) calloc(105,sizeof(modelica_real));
  jacobian->tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  jacobian->sparsePattern = (SPARSE_PATTERN*) malloc(sizeof(SPARSE_PATTERN));
  jacobian->sparsePattern->leadindex = (unsigned int*) malloc((105+1)*sizeof(int));
  jacobian->sparsePattern->index = (unsigned int*) malloc(983*sizeof(int));
  jacobian->sparsePattern->numberOfNoneZeros = 983;
  jacobian->sparsePattern->colorCols = (unsigned int*) malloc(105*sizeof(int));
  jacobian->sparsePattern->maxColors = 16;
  jacobian->constantEqns = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (105+1)*sizeof(int));
  
  for(i=2;i<105+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 983*sizeof(int));
  
  /* write color array */
  jacobian->sparsePattern->colorCols[6] = 1;
  jacobian->sparsePattern->colorCols[8] = 2;
  jacobian->sparsePattern->colorCols[10] = 3;
  jacobian->sparsePattern->colorCols[5] = 4;
  jacobian->sparsePattern->colorCols[7] = 5;
  jacobian->sparsePattern->colorCols[9] = 6;
  jacobian->sparsePattern->colorCols[1] = 7;
  jacobian->sparsePattern->colorCols[14] = 8;
  jacobian->sparsePattern->colorCols[17] = 8;
  jacobian->sparsePattern->colorCols[20] = 8;
  jacobian->sparsePattern->colorCols[74] = 8;
  jacobian->sparsePattern->colorCols[77] = 8;
  jacobian->sparsePattern->colorCols[80] = 8;
  jacobian->sparsePattern->colorCols[83] = 8;
  jacobian->sparsePattern->colorCols[45] = 8;
  jacobian->sparsePattern->colorCols[48] = 8;
  jacobian->sparsePattern->colorCols[51] = 8;
  jacobian->sparsePattern->colorCols[13] = 9;
  jacobian->sparsePattern->colorCols[16] = 9;
  jacobian->sparsePattern->colorCols[19] = 9;
  jacobian->sparsePattern->colorCols[3] = 9;
  jacobian->sparsePattern->colorCols[75] = 9;
  jacobian->sparsePattern->colorCols[78] = 9;
  jacobian->sparsePattern->colorCols[81] = 9;
  jacobian->sparsePattern->colorCols[44] = 9;
  jacobian->sparsePattern->colorCols[47] = 9;
  jacobian->sparsePattern->colorCols[50] = 9;
  jacobian->sparsePattern->colorCols[24] = 10;
  jacobian->sparsePattern->colorCols[27] = 10;
  jacobian->sparsePattern->colorCols[30] = 10;
  jacobian->sparsePattern->colorCols[4] = 10;
  jacobian->sparsePattern->colorCols[76] = 10;
  jacobian->sparsePattern->colorCols[79] = 10;
  jacobian->sparsePattern->colorCols[82] = 10;
  jacobian->sparsePattern->colorCols[55] = 10;
  jacobian->sparsePattern->colorCols[58] = 10;
  jacobian->sparsePattern->colorCols[61] = 10;
  jacobian->sparsePattern->colorCols[34] = 11;
  jacobian->sparsePattern->colorCols[37] = 11;
  jacobian->sparsePattern->colorCols[40] = 11;
  jacobian->sparsePattern->colorCols[0] = 11;
  jacobian->sparsePattern->colorCols[86] = 11;
  jacobian->sparsePattern->colorCols[89] = 11;
  jacobian->sparsePattern->colorCols[92] = 11;
  jacobian->sparsePattern->colorCols[65] = 11;
  jacobian->sparsePattern->colorCols[68] = 11;
  jacobian->sparsePattern->colorCols[71] = 11;
  jacobian->sparsePattern->colorCols[12] = 12;
  jacobian->sparsePattern->colorCols[15] = 12;
  jacobian->sparsePattern->colorCols[18] = 12;
  jacobian->sparsePattern->colorCols[2] = 12;
  jacobian->sparsePattern->colorCols[96] = 12;
  jacobian->sparsePattern->colorCols[99] = 12;
  jacobian->sparsePattern->colorCols[102] = 12;
  jacobian->sparsePattern->colorCols[43] = 12;
  jacobian->sparsePattern->colorCols[46] = 12;
  jacobian->sparsePattern->colorCols[49] = 12;
  jacobian->sparsePattern->colorCols[23] = 13;
  jacobian->sparsePattern->colorCols[26] = 13;
  jacobian->sparsePattern->colorCols[29] = 13;
  jacobian->sparsePattern->colorCols[21] = 13;
  jacobian->sparsePattern->colorCols[85] = 13;
  jacobian->sparsePattern->colorCols[88] = 13;
  jacobian->sparsePattern->colorCols[91] = 13;
  jacobian->sparsePattern->colorCols[94] = 13;
  jacobian->sparsePattern->colorCols[54] = 13;
  jacobian->sparsePattern->colorCols[57] = 13;
  jacobian->sparsePattern->colorCols[60] = 13;
  jacobian->sparsePattern->colorCols[52] = 13;
  jacobian->sparsePattern->colorCols[33] = 14;
  jacobian->sparsePattern->colorCols[36] = 14;
  jacobian->sparsePattern->colorCols[39] = 14;
  jacobian->sparsePattern->colorCols[32] = 14;
  jacobian->sparsePattern->colorCols[95] = 14;
  jacobian->sparsePattern->colorCols[98] = 14;
  jacobian->sparsePattern->colorCols[101] = 14;
  jacobian->sparsePattern->colorCols[104] = 14;
  jacobian->sparsePattern->colorCols[64] = 14;
  jacobian->sparsePattern->colorCols[67] = 14;
  jacobian->sparsePattern->colorCols[70] = 14;
  jacobian->sparsePattern->colorCols[63] = 14;
  jacobian->sparsePattern->colorCols[11] = 15;
  jacobian->sparsePattern->colorCols[25] = 15;
  jacobian->sparsePattern->colorCols[28] = 15;
  jacobian->sparsePattern->colorCols[31] = 15;
  jacobian->sparsePattern->colorCols[73] = 15;
  jacobian->sparsePattern->colorCols[87] = 15;
  jacobian->sparsePattern->colorCols[90] = 15;
  jacobian->sparsePattern->colorCols[93] = 15;
  jacobian->sparsePattern->colorCols[42] = 15;
  jacobian->sparsePattern->colorCols[56] = 15;
  jacobian->sparsePattern->colorCols[59] = 15;
  jacobian->sparsePattern->colorCols[62] = 15;
  jacobian->sparsePattern->colorCols[22] = 16;
  jacobian->sparsePattern->colorCols[35] = 16;
  jacobian->sparsePattern->colorCols[38] = 16;
  jacobian->sparsePattern->colorCols[41] = 16;
  jacobian->sparsePattern->colorCols[84] = 16;
  jacobian->sparsePattern->colorCols[97] = 16;
  jacobian->sparsePattern->colorCols[100] = 16;
  jacobian->sparsePattern->colorCols[103] = 16;
  jacobian->sparsePattern->colorCols[53] = 16;
  jacobian->sparsePattern->colorCols[66] = 16;
  jacobian->sparsePattern->colorCols[69] = 16;
  jacobian->sparsePattern->colorCols[72] = 16;
  TRACE_POP
  return 0;
}


