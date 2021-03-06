/*
 * Trigger_STARTUP_EVENT_8345p0002.c
 *
 * Code generation for model "BaseEngineController_A02_bak2.mdl".
 *
 * Model version              : 1.1532
 * Simulink Coder version : 8.0 (R2011a) 09-Mar-2011
 * C source code generated on : Tue Jan 01 10:29:48 2019
 *
 * Target selection: motohawk_ert_rtw.tlc
 * Embedded hardware selection: Specified
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BaseEngineController_A02_bak2.h"
#include "BaseEngineController_A02_bak2_private.h"

void Trigger_STARTUP_EVENT_8345p0002(void)
{
  /* Named constants for Stateflow: '<S800>/ECUP Latch' */
#define BaseEngineController_A02_bak2_IN_PowerDown (1U)
#define BaseEngineController_A02_bak2_IN_PowerUp (2U)

  {
    /* Output and update for function-call system: '<S546>/Once at Startup' */
    {
      /* local block i/o variables */
      uint16_T rtb_motohawk_ain;

      /* S-Function Block: <S596>/motohawk_ain Resource: MAPSensorPin */
      {
        extern NativeError_S MAPSensorPin_AnalogInput_Get(uint16_T *adc,
          uint16_T *status);
        MAPSensorPin_AnalogInput_Get(&rtb_motohawk_ain, NULL);
      }

      /* DataTypeConversion: '<S596>/Data Type Conversion' incorporates:
       *  S-Function (motohawk_sfun_ain): '<S596>/motohawk_ain'
       */
      BaseEngineController_A02_bak2_B.s546_Merge = (real_T)rtb_motohawk_ain;
    }
  }
}
