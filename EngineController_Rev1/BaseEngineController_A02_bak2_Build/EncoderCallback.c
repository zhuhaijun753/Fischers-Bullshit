/*
 * EncoderCallback.c
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

#include "Application.h"

uint8_T motohawk_encoder_status = 0;
uint8_T motohawk_encoder_fault = 0;
void EncoderStateCallback(E_EncoderStatus in_eEncoderStatus, NativePtrSizedInt_U
  in_uAppDataToSendOnNotify)
{
  motohawk_encoder_status = (uint8_T) in_eEncoderStatus;
}

void EncoderDiagnosticsCallback(E_EncoderError in_eEncoderError,
  NativePtrSizedInt_U in_uAppDataToSendOnNotify)
{
  motohawk_encoder_fault = ((uint8_T) in_eEncoderError) + 1;

  {
    extern void ReSyncAfterCrankUnsync_24(void);
    ReSyncAfterCrankUnsync_24();
  }

  {
    extern void Trigger_Encoder_Fault_33(void);
    Trigger_Encoder_Fault_33();
  }
}
