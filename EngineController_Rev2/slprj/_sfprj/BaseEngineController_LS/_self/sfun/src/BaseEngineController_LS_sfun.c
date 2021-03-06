/* Include files */

#include "BaseEngineController_LS_sfun.h"
#include "c1_BaseEngineController_LS.h"
#include "c2_BaseEngineController_LS.h"
#include "c3_BaseEngineController_LS.h"
#include "c7_BaseEngineController_LS.h"
#include "c8_BaseEngineController_LS.h"
#include "c9_BaseEngineController_LS.h"
#include "c11_BaseEngineController_LS.h"
#include "c12_BaseEngineController_LS.h"
#include "c19_BaseEngineController_LS.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _BaseEngineController_LSMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void BaseEngineController_LS_initializer(void)
{
}

void BaseEngineController_LS_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_BaseEngineController_LS_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_BaseEngineController_LS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_BaseEngineController_LS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_BaseEngineController_LS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_BaseEngineController_LS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_BaseEngineController_LS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_BaseEngineController_LS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_BaseEngineController_LS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_BaseEngineController_LS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_BaseEngineController_LS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_BaseEngineController_LS_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(250125841U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2495892468U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1300757434U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3544658954U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3090578895U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2368636319U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(674888380U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(54628353U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_BaseEngineController_LS_get_check_sum(mxArray *plhs[]);
          sf_c1_BaseEngineController_LS_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_BaseEngineController_LS_get_check_sum(mxArray *plhs[]);
          sf_c2_BaseEngineController_LS_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_BaseEngineController_LS_get_check_sum(mxArray *plhs[]);
          sf_c3_BaseEngineController_LS_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_BaseEngineController_LS_get_check_sum(mxArray *plhs[]);
          sf_c7_BaseEngineController_LS_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_BaseEngineController_LS_get_check_sum(mxArray *plhs[]);
          sf_c8_BaseEngineController_LS_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_BaseEngineController_LS_get_check_sum(mxArray *plhs[]);
          sf_c9_BaseEngineController_LS_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_BaseEngineController_LS_get_check_sum(mxArray *
            plhs[]);
          sf_c11_BaseEngineController_LS_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_BaseEngineController_LS_get_check_sum(mxArray *
            plhs[]);
          sf_c12_BaseEngineController_LS_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_BaseEngineController_LS_get_check_sum(mxArray *
            plhs[]);
          sf_c19_BaseEngineController_LS_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3176360410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1862911626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(659157607U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1884031890U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3504993308U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(356830974U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(698084745U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(802608111U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_BaseEngineController_LS_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_BaseEngineController_LS_get_autoinheritance_info
          (void);
        plhs[0] = sf_c1_BaseEngineController_LS_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_BaseEngineController_LS_get_autoinheritance_info
          (void);
        plhs[0] = sf_c2_BaseEngineController_LS_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_BaseEngineController_LS_get_autoinheritance_info
          (void);
        plhs[0] = sf_c3_BaseEngineController_LS_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_BaseEngineController_LS_get_autoinheritance_info
          (void);
        plhs[0] = sf_c7_BaseEngineController_LS_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_BaseEngineController_LS_get_autoinheritance_info
          (void);
        plhs[0] = sf_c8_BaseEngineController_LS_get_autoinheritance_info();
        break;
      }

     case 9:
      {
        extern mxArray *sf_c9_BaseEngineController_LS_get_autoinheritance_info
          (void);
        plhs[0] = sf_c9_BaseEngineController_LS_get_autoinheritance_info();
        break;
      }

     case 11:
      {
        extern mxArray *sf_c11_BaseEngineController_LS_get_autoinheritance_info
          (void);
        plhs[0] = sf_c11_BaseEngineController_LS_get_autoinheritance_info();
        break;
      }

     case 12:
      {
        extern mxArray *sf_c12_BaseEngineController_LS_get_autoinheritance_info
          (void);
        plhs[0] = sf_c12_BaseEngineController_LS_get_autoinheritance_info();
        break;
      }

     case 19:
      {
        extern mxArray *sf_c19_BaseEngineController_LS_get_autoinheritance_info
          (void);
        plhs[0] = sf_c19_BaseEngineController_LS_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_BaseEngineController_LS_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_BaseEngineController_LS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_BaseEngineController_LS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_BaseEngineController_LS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_BaseEngineController_LS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_BaseEngineController_LS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_BaseEngineController_LS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_BaseEngineController_LS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_BaseEngineController_LS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_BaseEngineController_LS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_BaseEngineController_LS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_BaseEngineController_LS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_BaseEngineController_LS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_BaseEngineController_LS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_BaseEngineController_LS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_BaseEngineController_LS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_BaseEngineController_LS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_BaseEngineController_LS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_BaseEngineController_LS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void BaseEngineController_LS_debug_initialize(void)
{
  _BaseEngineController_LSMachineNumber_ = sf_debug_initialize_machine(
    "BaseEngineController_LS","sfun",0,9,0,0,0);
  sf_debug_set_machine_event_thresholds(_BaseEngineController_LSMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(_BaseEngineController_LSMachineNumber_,0);
}

void BaseEngineController_LS_register_exported_symbols(SimStruct* S)
{
}
