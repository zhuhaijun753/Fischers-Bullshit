/*
 * Trigger_FGND_MID_TDC_EVENT_8045p0005.c
 *
 * Code generation for model "BaseEngineController_LS.mdl".
 *
 * Model version              : 1.1987
 * Simulink Coder version : 8.0 (R2011a) 09-Mar-2011
 * C source code generated on : Sun Oct 04 18:30:28 2020
 *
 * Target selection: motohawk_ert_rtw.tlc
 * Embedded hardware selection: Specified
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BaseEngineController_LS.h"
#include "BaseEngineController_LS_private.h"

void Trigger_FGND_MID_TDC_EVENT_8045p0005(void)
{
  /* Named constants for Stateflow: '<S913>/ECUP Latch' */
#define BaseEngineController_LS_IN_PowerDown (1U)
#define BaseEngineController_LS_IN_PowerUp (2U)

  {
    extern void Timer_FreeRunningCounter_GetTime(uint32_T *lower32Bits, uint32_T
      *upper32Bits);
    uint32_T lower32Bits;
    uint32_T upper32Bits;
    Timer_FreeRunningCounter_GetTime(&lower32Bits, &upper32Bits);
    BaseEngineController_LS_M->Timing.clockTick0 = lower32Bits;
    BaseEngineController_LS_M->Timing.clockTickH0 = upper32Bits;
  }

  if (BaseEngineController_LS_DWork.s506_motohawk_trigger5_DWORK1) {
    /* Output and update for function-call system: '<S506>/MID_TDC' */
    {
      /* local block i/o variables */
      uint16_T rtb_motohawk_ain_read;

      /* S-Function Block: <S555>/motohawk_ain_read Resource: MAPSensorPin */
      {
        extern NativeError_S MAPSensorPin_AnalogInput_Get(uint16_T *adc,
          uint16_T *status);
        MAPSensorPin_AnalogInput_Get(&rtb_motohawk_ain_read, NULL);
      }

      /* DataTypeConversion: '<S555>/Data Type Conversion' incorporates:
       *  S-Function (motohawk_sfun_ain_read): '<S555>/motohawk_ain_read'
       */
      BaseEngineController_LS_B.s506_Merge = (real_T)rtb_motohawk_ain_read;
    }
  }
}
