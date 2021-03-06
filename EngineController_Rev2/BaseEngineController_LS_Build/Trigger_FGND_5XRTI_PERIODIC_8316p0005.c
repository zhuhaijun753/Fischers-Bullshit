/*
 * Trigger_FGND_5XRTI_PERIODIC_8316p0005.c
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

void Trigger_FGND_5XRTI_PERIODIC_8316p0005(void)
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

  if (BaseEngineController_LS_DWork.s446_motohawk_trigger_DWORK1) {
    /* Output and update for function-call system: '<S446>/Temp Sensors' */
    {
      /* local block i/o variables */
      real_T rtb_DataTypeConversion_o;
      real_T rtb_UnitDelay_di;
      real_T rtb_DataTypeConversion_k;
      real_T rtb_UnitDelay_jh;
      real_T rtb_DataTypeConversion_k3;
      real_T rtb_UnitDelay_i;
      real_T rtb_Merge_l;
      real_T rtb_DataTypeConversion_i;
      real_T rtb_UnitDelay_kw;
      real_T rtb_Merge_l5;
      real_T rtb_Product_d0;
      index_T rtb_motohawk_prelookup_h;
      index_T rtb_motohawk_prelookup_a;
      index_T rtb_motohawk_prelookup_gz;
      index_T rtb_motohawk_prelookup_b;
      boolean_T rtb_LogicalOperator2_k;
      boolean_T rtb_LogicalOperator3_h;
      boolean_T rtb_LogicalOperator2_p;
      boolean_T rtb_LogicalOperator3_ht;
      boolean_T rtb_LogicalOperator2_f;
      boolean_T rtb_LogicalOperator3_j;
      boolean_T rtb_LogicalOperator2_i;
      boolean_T rtb_LogicalOperator3_p;
      boolean_T rtb_LogicalOperator4;
      boolean_T rtb_LogicalOperator1_b;
      real_T rtb_Sum1_h;
      real_T rtb_Sum1_hn;
      real_T rtb_Sum1_g;
      real_T rtb_Sum1_lf;

      /* S-Function Block: <S668>/motohawk_delta_time */
      {
        uint32_T delta;
        extern uint32_T Timer_FreeRunningCounter_GetDeltaUpdateReference_us
          (uint32_T * pReference_lower32Bits, uint32_T *pReference_upper32Bits);
        delta = Timer_FreeRunningCounter_GetDeltaUpdateReference_us
          (&BaseEngineController_LS_DWork.s668_motohawk_delta_time_DWORK1, NULL);
        rtb_Product_d0 = ((real_T) delta) * 0.000001;
      }

      /* Product: '<S668>/Product' incorporates:
       *  MinMax: '<S668>/MinMax'
       *  S-Function (motohawk_sfun_calibration): '<S668>/motohawk_calibration'
       */
      rtb_Product_d0 /= (rtb_Product_d0 >= (ECTFiltConst_DataStore())) ||
        rtIsNaN((ECTFiltConst_DataStore())) ? rtb_Product_d0 :
        (ECTFiltConst_DataStore());

      /* Logic: '<S656>/Logical Operator4' incorporates:
       *  S-Function (motohawk_sfun_fault_status): '<S656>/motohawk_fault_status1'
       *  S-Function (motohawk_sfun_fault_status): '<S656>/motohawk_fault_status4'
       */
      rtb_LogicalOperator4 = (IsFaultActive(32) || IsFaultActive(33));

      /* Logic: '<S656>/Logical Operator1' incorporates:
       *  S-Function (motohawk_sfun_fault_status): '<S656>/motohawk_fault_status2'
       *  S-Function (motohawk_sfun_fault_status): '<S656>/motohawk_fault_status3'
       */
      rtb_LogicalOperator1_b = (IsFaultSuspected(32) || IsFaultSuspected(33));

      /* S-Function Block: <S582>/motohawk_ain Resource: ECTSensorPin */
      {
        extern NativeError_S ECTSensorPin_AnalogInput_Get(uint16_T *adc,
          uint16_T *status);
        ECTSensorPin_AnalogInput_Get
          (&BaseEngineController_LS_B.s582_motohawk_ain, NULL);
      }

      /* DataTypeConversion: '<S656>/Data Type Conversion' */
      rtb_DataTypeConversion_o = (real_T)
        BaseEngineController_LS_B.s582_motohawk_ain;

      /* S-Function Block: <S673>/motohawk_prelookup */
      {
        extern uint16_T TablePrelookup_real_T(real_T in, const volatile real_T
          ordarr[], uint32_T sz, uint16_T prev);
        (ECTIdx_DataStore()) = TablePrelookup_real_T(rtb_DataTypeConversion_o,
          (ECTIdxArr_DataStore()), 13, (ECTIdx_DataStore()));
        rtb_motohawk_prelookup_h = (ECTIdx_DataStore());
      }

      /* S-Function Block: <S673>/motohawk_interpolation_1d */
      {
        extern real_T TableInterpolation1D_real_T(uint16_T idx, real_T *tbl_data,
          uint32_T sz);
        BaseEngineController_LS_B.s673_motohawk_interpolation_1d =
          TableInterpolation1D_real_T(rtb_motohawk_prelookup_h, (real_T *)
          ((ECTTbl_DataStore())), 13);
      }

      /* UnitDelay: '<S656>/Unit Delay' */
      rtb_UnitDelay_di = BaseEngineController_LS_DWork.s656_UnitDelay_DSTATE;

      /* If: '<S656>/If' incorporates:
       *  Logic: '<S656>/Logical Operator5'
       *  Logic: '<S656>/Logical Operator6'
       */
      if ((!rtb_LogicalOperator4) && rtb_LogicalOperator1_b) {
        /* Outputs for IfAction SubSystem: '<S656>/If Action Subsystem' incorporates:
         *  ActionPort: '<S669>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem(rtb_UnitDelay_di,
          &BaseEngineController_LS_B.s656_Merge);

        /* End of Outputs for SubSystem: '<S656>/If Action Subsystem' */
      } else if (rtb_LogicalOperator4) {
        /* Outputs for IfAction SubSystem: '<S656>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S670>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem((ECTDefault_DataStore()),
          &BaseEngineController_LS_B.s656_Merge);

        /* End of Outputs for SubSystem: '<S656>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S656>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S671>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem
          (BaseEngineController_LS_B.s673_motohawk_interpolation_1d,
           &BaseEngineController_LS_B.s656_Merge);

        /* End of Outputs for SubSystem: '<S656>/If Action Subsystem2' */
      }

      /* End of If: '<S656>/If' */

      /* Sum: '<S674>/Sum1' incorporates:
       *  Constant: '<S674>/Constant'
       *  Product: '<S674>/Product'
       *  Product: '<S674>/Product1'
       *  Sum: '<S674>/Sum'
       *  UnitDelay: '<S674>/Unit Delay'
       */
      rtb_Sum1_h = (1.0 - rtb_Product_d0) *
        BaseEngineController_LS_DWork.s674_UnitDelay_DSTATE +
        BaseEngineController_LS_B.s656_Merge * rtb_Product_d0;

      /* If: '<S672>/If' incorporates:
       *  Inport: '<S675>/In1'
       *  Inport: '<S676>/In1'
       *  S-Function (motohawk_sfun_calibration): '<S672>/new_value'
       *  S-Function (motohawk_sfun_calibration): '<S672>/override_enable'
       */
      if ((ECT_ovr_DataStore())) {
        /* Outputs for IfAction SubSystem: '<S672>/NewValue' incorporates:
         *  ActionPort: '<S675>/Action Port'
         */
        BaseEngineController_LS_B.s672_Merge = (ECT_new_DataStore());

        /* End of Outputs for SubSystem: '<S672>/NewValue' */
      } else {
        /* Outputs for IfAction SubSystem: '<S672>/OldValue' incorporates:
         *  ActionPort: '<S676>/Action Port'
         */
        BaseEngineController_LS_B.s672_Merge = rtb_Sum1_h;

        /* End of Outputs for SubSystem: '<S672>/OldValue' */
      }

      /* End of If: '<S672>/If' */

      /* Logic: '<S656>/Logical Operator2' incorporates:
       *  RelationalOperator: '<S656>/Relational Operator2'
       *  S-Function (motohawk_sfun_calibration): '<S656>/motohawk_calibration1'
       *  S-Function (motohawk_sfun_data_read): '<S656>/motohawk_data_read1'
       */
      rtb_LogicalOperator2_k = ((MPRD_DataStore() && (rtb_DataTypeConversion_o >
                                  (ECTMax_DataStore()))));

      /* S-Function (motohawk_sfun_fault_def): '<S656>/motohawk_fault_def2' */

      /* Set Fault Suspected Status: ECTRangeHigh */
      {
        extern void SetFaultSuspected(uint32_T fault, boolean_T val);
        extern void UpdateFault(uint32_T fault);
        SetFaultSuspected(32, rtb_LogicalOperator2_k);
        UpdateFault(32);
      }

      /* Logic: '<S656>/Logical Operator3' incorporates:
       *  RelationalOperator: '<S656>/Relational Operator3'
       *  S-Function (motohawk_sfun_calibration): '<S656>/motohawk_calibration6'
       *  S-Function (motohawk_sfun_data_read): '<S656>/motohawk_data_read1'
       */
      rtb_LogicalOperator3_h = ((MPRD_DataStore() && (rtb_DataTypeConversion_o <
                                  (ECTMin_DataStore()))));

      /* S-Function (motohawk_sfun_fault_def): '<S656>/motohawk_fault_def3' */

      /* Set Fault Suspected Status: ECTRangeLow */
      {
        extern void SetFaultSuspected(uint32_T fault, boolean_T val);
        extern void UpdateFault(uint32_T fault);
        SetFaultSuspected(33, rtb_LogicalOperator3_h);
        UpdateFault(33);
      }

      /* S-Function Block: <S686>/motohawk_delta_time */
      {
        uint32_T delta;
        extern uint32_T Timer_FreeRunningCounter_GetDeltaUpdateReference_us
          (uint32_T * pReference_lower32Bits, uint32_T *pReference_upper32Bits);
        delta = Timer_FreeRunningCounter_GetDeltaUpdateReference_us
          (&BaseEngineController_LS_DWork.s686_motohawk_delta_time_DWORK1, NULL);
        rtb_Product_d0 = ((real_T) delta) * 0.000001;
      }

      /* Product: '<S686>/Product' incorporates:
       *  MinMax: '<S686>/MinMax'
       *  S-Function (motohawk_sfun_calibration): '<S686>/motohawk_calibration'
       */
      rtb_Product_d0 /= (rtb_Product_d0 >= (IATFiltConst_DataStore())) ||
        rtIsNaN((IATFiltConst_DataStore())) ? rtb_Product_d0 :
        (IATFiltConst_DataStore());

      /* Logic: '<S658>/Logical Operator4' incorporates:
       *  S-Function (motohawk_sfun_fault_status): '<S658>/motohawk_fault_status1'
       *  S-Function (motohawk_sfun_fault_status): '<S658>/motohawk_fault_status4'
       */
      rtb_LogicalOperator4 = (IsFaultActive(66) || IsFaultActive(67));

      /* Logic: '<S658>/Logical Operator1' incorporates:
       *  S-Function (motohawk_sfun_fault_status): '<S658>/motohawk_fault_status2'
       *  S-Function (motohawk_sfun_fault_status): '<S658>/motohawk_fault_status3'
       */
      rtb_LogicalOperator1_b = (IsFaultSuspected(66) || IsFaultSuspected(67));

      /* S-Function Block: <S582>/motohawk_ain1 Resource: IATSensorPin */
      {
        extern NativeError_S IATSensorPin_AnalogInput_Get(uint16_T *adc,
          uint16_T *status);
        IATSensorPin_AnalogInput_Get
          (&BaseEngineController_LS_B.s582_motohawk_ain1, NULL);
      }

      /* DataTypeConversion: '<S658>/Data Type Conversion' */
      rtb_DataTypeConversion_k = (real_T)
        BaseEngineController_LS_B.s582_motohawk_ain1;

      /* S-Function Block: <S691>/motohawk_prelookup */
      {
        extern uint16_T TablePrelookup_real_T(real_T in, const volatile real_T
          ordarr[], uint32_T sz, uint16_T prev);
        (IATIdx_DataStore()) = TablePrelookup_real_T(rtb_DataTypeConversion_k,
          (IATIdxArr_DataStore()), 13, (IATIdx_DataStore()));
        rtb_motohawk_prelookup_a = (IATIdx_DataStore());
      }

      /* S-Function Block: <S691>/motohawk_interpolation_1d */
      {
        extern real_T TableInterpolation1D_real_T(uint16_T idx, real_T *tbl_data,
          uint32_T sz);
        BaseEngineController_LS_B.s691_motohawk_interpolation_1d =
          TableInterpolation1D_real_T(rtb_motohawk_prelookup_a, (real_T *)
          ((IATTbl_DataStore())), 13);
      }

      /* UnitDelay: '<S658>/Unit Delay' */
      rtb_UnitDelay_jh = BaseEngineController_LS_DWork.s658_UnitDelay_DSTATE;

      /* If: '<S658>/If' incorporates:
       *  Logic: '<S658>/Logical Operator5'
       *  Logic: '<S658>/Logical Operator6'
       */
      if ((!rtb_LogicalOperator4) && rtb_LogicalOperator1_b) {
        /* Outputs for IfAction SubSystem: '<S658>/If Action Subsystem' incorporates:
         *  ActionPort: '<S687>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem(rtb_UnitDelay_jh,
          &BaseEngineController_LS_B.s658_Merge);

        /* End of Outputs for SubSystem: '<S658>/If Action Subsystem' */
      } else if (rtb_LogicalOperator4) {
        /* Outputs for IfAction SubSystem: '<S658>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S688>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem((IATDefault_DataStore()),
          &BaseEngineController_LS_B.s658_Merge);

        /* End of Outputs for SubSystem: '<S658>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S658>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S689>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem
          (BaseEngineController_LS_B.s691_motohawk_interpolation_1d,
           &BaseEngineController_LS_B.s658_Merge);

        /* End of Outputs for SubSystem: '<S658>/If Action Subsystem2' */
      }

      /* End of If: '<S658>/If' */

      /* Sum: '<S692>/Sum1' incorporates:
       *  Constant: '<S692>/Constant'
       *  Product: '<S692>/Product'
       *  Product: '<S692>/Product1'
       *  Sum: '<S692>/Sum'
       *  UnitDelay: '<S692>/Unit Delay'
       */
      rtb_Sum1_hn = (1.0 - rtb_Product_d0) *
        BaseEngineController_LS_DWork.s692_UnitDelay_DSTATE +
        BaseEngineController_LS_B.s658_Merge * rtb_Product_d0;

      /* If: '<S690>/If' incorporates:
       *  Inport: '<S693>/In1'
       *  Inport: '<S694>/In1'
       *  S-Function (motohawk_sfun_calibration): '<S690>/new_value'
       *  S-Function (motohawk_sfun_calibration): '<S690>/override_enable'
       */
      if ((IAT_ovr_DataStore())) {
        /* Outputs for IfAction SubSystem: '<S690>/NewValue' incorporates:
         *  ActionPort: '<S693>/Action Port'
         */
        BaseEngineController_LS_B.s690_Merge = (IAT_new_DataStore());

        /* End of Outputs for SubSystem: '<S690>/NewValue' */
      } else {
        /* Outputs for IfAction SubSystem: '<S690>/OldValue' incorporates:
         *  ActionPort: '<S694>/Action Port'
         */
        BaseEngineController_LS_B.s690_Merge = rtb_Sum1_hn;

        /* End of Outputs for SubSystem: '<S690>/OldValue' */
      }

      /* End of If: '<S690>/If' */

      /* Logic: '<S658>/Logical Operator2' incorporates:
       *  RelationalOperator: '<S658>/Relational Operator2'
       *  S-Function (motohawk_sfun_calibration): '<S658>/motohawk_calibration1'
       *  S-Function (motohawk_sfun_data_read): '<S658>/motohawk_data_read1'
       */
      rtb_LogicalOperator2_p = ((MPRD_DataStore() && (rtb_DataTypeConversion_k >
                                  (IATMax_DataStore()))));

      /* S-Function (motohawk_sfun_fault_def): '<S658>/motohawk_fault_def2' */

      /* Set Fault Suspected Status: IATRangeHigh */
      {
        extern void SetFaultSuspected(uint32_T fault, boolean_T val);
        extern void UpdateFault(uint32_T fault);
        SetFaultSuspected(66, rtb_LogicalOperator2_p);
        UpdateFault(66);
      }

      /* Logic: '<S658>/Logical Operator3' incorporates:
       *  RelationalOperator: '<S658>/Relational Operator3'
       *  S-Function (motohawk_sfun_calibration): '<S658>/motohawk_calibration6'
       *  S-Function (motohawk_sfun_data_read): '<S658>/motohawk_data_read1'
       */
      rtb_LogicalOperator3_ht = ((MPRD_DataStore() && (rtb_DataTypeConversion_k <
                                   (IATMin_DataStore()))));

      /* S-Function (motohawk_sfun_fault_def): '<S658>/motohawk_fault_def3' */

      /* Set Fault Suspected Status: IATRangeLow */
      {
        extern void SetFaultSuspected(uint32_T fault, boolean_T val);
        extern void UpdateFault(uint32_T fault);
        SetFaultSuspected(67, rtb_LogicalOperator3_ht);
        UpdateFault(67);
      }

      /* S-Function Block: <S677>/motohawk_delta_time */
      {
        uint32_T delta;
        extern uint32_T Timer_FreeRunningCounter_GetDeltaUpdateReference_us
          (uint32_T * pReference_lower32Bits, uint32_T *pReference_upper32Bits);
        delta = Timer_FreeRunningCounter_GetDeltaUpdateReference_us
          (&BaseEngineController_LS_DWork.s677_motohawk_delta_time_DWORK1, NULL);
        rtb_Product_d0 = ((real_T) delta) * 0.000001;
      }

      /* Product: '<S677>/Product' incorporates:
       *  MinMax: '<S677>/MinMax'
       *  S-Function (motohawk_sfun_calibration): '<S677>/motohawk_calibration'
       */
      rtb_Product_d0 /= (rtb_Product_d0 >= (EVAPFiltConst_DataStore())) ||
        rtIsNaN((EVAPFiltConst_DataStore())) ? rtb_Product_d0 :
        (EVAPFiltConst_DataStore());

      /* Logic: '<S657>/Logical Operator4' incorporates:
       *  S-Function (motohawk_sfun_fault_status): '<S657>/motohawk_fault_status1'
       *  S-Function (motohawk_sfun_fault_status): '<S657>/motohawk_fault_status4'
       */
      rtb_LogicalOperator4 = (IsFaultActive(54) || IsFaultActive(55));

      /* Logic: '<S657>/Logical Operator1' incorporates:
       *  S-Function (motohawk_sfun_fault_status): '<S657>/motohawk_fault_status2'
       *  S-Function (motohawk_sfun_fault_status): '<S657>/motohawk_fault_status3'
       */
      rtb_LogicalOperator1_b = (IsFaultSuspected(54) || IsFaultSuspected(55));

      /* S-Function Block: <S582>/motohawk_ain2 Resource: EVAPSensorPin */
      {
        extern NativeError_S EVAPSensorPin_AnalogInput_Get(uint16_T *adc,
          uint16_T *status);
        EVAPSensorPin_AnalogInput_Get
          (&BaseEngineController_LS_B.s582_motohawk_ain2, NULL);
      }

      /* DataTypeConversion: '<S657>/Data Type Conversion' */
      rtb_DataTypeConversion_k3 = (real_T)
        BaseEngineController_LS_B.s582_motohawk_ain2;

      /* S-Function Block: <S682>/motohawk_prelookup */
      {
        extern uint16_T TablePrelookup_real_T(real_T in, const volatile real_T
          ordarr[], uint32_T sz, uint16_T prev);
        (EVAPIdx_DataStore()) = TablePrelookup_real_T(rtb_DataTypeConversion_k3,
          (EVAPIdxArr_DataStore()), 13, (EVAPIdx_DataStore()));
        rtb_motohawk_prelookup_gz = (EVAPIdx_DataStore());
      }

      /* S-Function Block: <S682>/motohawk_interpolation_1d */
      {
        extern real_T TableInterpolation1D_real_T(uint16_T idx, real_T *tbl_data,
          uint32_T sz);
        BaseEngineController_LS_B.s682_motohawk_interpolation_1d =
          TableInterpolation1D_real_T(rtb_motohawk_prelookup_gz, (real_T *)
          ((EVAPTbl_DataStore())), 13);
      }

      /* UnitDelay: '<S657>/Unit Delay' */
      rtb_UnitDelay_i = BaseEngineController_LS_DWork.s657_UnitDelay_DSTATE;

      /* If: '<S657>/If' incorporates:
       *  Logic: '<S657>/Logical Operator5'
       *  Logic: '<S657>/Logical Operator6'
       */
      if ((!rtb_LogicalOperator4) && rtb_LogicalOperator1_b) {
        /* Outputs for IfAction SubSystem: '<S657>/If Action Subsystem' incorporates:
         *  ActionPort: '<S678>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem(rtb_UnitDelay_i, &rtb_Merge_l);

        /* End of Outputs for SubSystem: '<S657>/If Action Subsystem' */
      } else if (rtb_LogicalOperator4) {
        /* Outputs for IfAction SubSystem: '<S657>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S679>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem((EVAPDefault_DataStore()),
          &rtb_Merge_l);

        /* End of Outputs for SubSystem: '<S657>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S657>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S680>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem
          (BaseEngineController_LS_B.s682_motohawk_interpolation_1d,
           &rtb_Merge_l);

        /* End of Outputs for SubSystem: '<S657>/If Action Subsystem2' */
      }

      /* End of If: '<S657>/If' */

      /* Sum: '<S683>/Sum1' incorporates:
       *  Constant: '<S683>/Constant'
       *  Product: '<S683>/Product'
       *  Product: '<S683>/Product1'
       *  Sum: '<S683>/Sum'
       *  UnitDelay: '<S683>/Unit Delay'
       */
      rtb_Sum1_g = (1.0 - rtb_Product_d0) *
        BaseEngineController_LS_DWork.s683_UnitDelay_DSTATE + rtb_Merge_l *
        rtb_Product_d0;

      /* If: '<S681>/If' incorporates:
       *  Inport: '<S684>/In1'
       *  Inport: '<S685>/In1'
       *  S-Function (motohawk_sfun_calibration): '<S681>/new_value'
       *  S-Function (motohawk_sfun_calibration): '<S681>/override_enable'
       */
      if ((EVAP_ovr_DataStore())) {
        /* Outputs for IfAction SubSystem: '<S681>/NewValue' incorporates:
         *  ActionPort: '<S684>/Action Port'
         */
        BaseEngineController_LS_B.s681_Merge = (EVAP_new_DataStore());

        /* End of Outputs for SubSystem: '<S681>/NewValue' */
      } else {
        /* Outputs for IfAction SubSystem: '<S681>/OldValue' incorporates:
         *  ActionPort: '<S685>/Action Port'
         */
        BaseEngineController_LS_B.s681_Merge = rtb_Sum1_g;

        /* End of Outputs for SubSystem: '<S681>/OldValue' */
      }

      /* End of If: '<S681>/If' */

      /* Logic: '<S657>/Logical Operator2' incorporates:
       *  RelationalOperator: '<S657>/Relational Operator2'
       *  S-Function (motohawk_sfun_calibration): '<S657>/motohawk_calibration1'
       *  S-Function (motohawk_sfun_data_read): '<S657>/motohawk_data_read1'
       */
      rtb_LogicalOperator2_f = ((MPRD_DataStore() && (rtb_DataTypeConversion_k3 >
                                  (EVAPMax_DataStore()))));

      /* S-Function (motohawk_sfun_fault_def): '<S657>/motohawk_fault_def2' */

      /* Set Fault Suspected Status: EVAPRangeHigh */
      {
        extern void SetFaultSuspected(uint32_T fault, boolean_T val);
        extern void UpdateFault(uint32_T fault);
        SetFaultSuspected(54, rtb_LogicalOperator2_f);
        UpdateFault(54);
      }

      /* Logic: '<S657>/Logical Operator3' incorporates:
       *  RelationalOperator: '<S657>/Relational Operator3'
       *  S-Function (motohawk_sfun_calibration): '<S657>/motohawk_calibration6'
       *  S-Function (motohawk_sfun_data_read): '<S657>/motohawk_data_read1'
       */
      rtb_LogicalOperator3_j = ((MPRD_DataStore() && (rtb_DataTypeConversion_k3 <
                                  (EVAPMin_DataStore()))));

      /* S-Function (motohawk_sfun_fault_def): '<S657>/motohawk_fault_def3' */

      /* Set Fault Suspected Status: EVAPRangeLow */
      {
        extern void SetFaultSuspected(uint32_T fault, boolean_T val);
        extern void UpdateFault(uint32_T fault);
        SetFaultSuspected(55, rtb_LogicalOperator3_j);
        UpdateFault(55);
      }

      /* S-Function Block: <S659>/motohawk_delta_time */
      {
        uint32_T delta;
        extern uint32_T Timer_FreeRunningCounter_GetDeltaUpdateReference_us
          (uint32_T * pReference_lower32Bits, uint32_T *pReference_upper32Bits);
        delta = Timer_FreeRunningCounter_GetDeltaUpdateReference_us
          (&BaseEngineController_LS_DWork.s659_motohawk_delta_time_DWORK1, NULL);
        rtb_Product_d0 = ((real_T) delta) * 0.000001;
      }

      /* Product: '<S659>/Product' incorporates:
       *  MinMax: '<S659>/MinMax'
       *  S-Function (motohawk_sfun_calibration): '<S659>/motohawk_calibration'
       */
      rtb_Product_d0 /= (rtb_Product_d0 >= (CATFiltConst_DataStore())) ||
        rtIsNaN((CATFiltConst_DataStore())) ? rtb_Product_d0 :
        (CATFiltConst_DataStore());

      /* Logic: '<S655>/Logical Operator4' incorporates:
       *  S-Function (motohawk_sfun_fault_status): '<S655>/motohawk_fault_status1'
       *  S-Function (motohawk_sfun_fault_status): '<S655>/motohawk_fault_status4'
       */
      rtb_LogicalOperator4 = (IsFaultActive(25) || IsFaultActive(26));

      /* Logic: '<S655>/Logical Operator1' incorporates:
       *  S-Function (motohawk_sfun_fault_status): '<S655>/motohawk_fault_status2'
       *  S-Function (motohawk_sfun_fault_status): '<S655>/motohawk_fault_status3'
       */
      rtb_LogicalOperator1_b = (IsFaultSuspected(25) || IsFaultSuspected(26));

      /* S-Function Block: <S582>/motohawk_ain3 Resource: CATSensorPin */
      {
        extern NativeError_S CATSensorPin_AnalogInput_Get(uint16_T *adc,
          uint16_T *status);
        CATSensorPin_AnalogInput_Get
          (&BaseEngineController_LS_B.s582_motohawk_ain3, NULL);
      }

      /* DataTypeConversion: '<S655>/Data Type Conversion' */
      rtb_DataTypeConversion_i = (real_T)
        BaseEngineController_LS_B.s582_motohawk_ain3;

      /* S-Function Block: <S664>/motohawk_prelookup */
      {
        extern uint16_T TablePrelookup_real_T(real_T in, const volatile real_T
          ordarr[], uint32_T sz, uint16_T prev);
        (CATIdx_DataStore()) = TablePrelookup_real_T(rtb_DataTypeConversion_i,
          (CATIdxArr_DataStore()), 13, (CATIdx_DataStore()));
        rtb_motohawk_prelookup_b = (CATIdx_DataStore());
      }

      /* S-Function Block: <S664>/motohawk_interpolation_1d */
      {
        extern real_T TableInterpolation1D_real_T(uint16_T idx, real_T *tbl_data,
          uint32_T sz);
        BaseEngineController_LS_B.s664_motohawk_interpolation_1d =
          TableInterpolation1D_real_T(rtb_motohawk_prelookup_b, (real_T *)
          ((CATTbl_DataStore())), 13);
      }

      /* UnitDelay: '<S655>/Unit Delay' */
      rtb_UnitDelay_kw = BaseEngineController_LS_DWork.s655_UnitDelay_DSTATE;

      /* If: '<S655>/If' incorporates:
       *  Logic: '<S655>/Logical Operator5'
       *  Logic: '<S655>/Logical Operator6'
       */
      if ((!rtb_LogicalOperator4) && rtb_LogicalOperator1_b) {
        /* Outputs for IfAction SubSystem: '<S655>/If Action Subsystem' incorporates:
         *  ActionPort: '<S660>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem(rtb_UnitDelay_kw,
          &rtb_Merge_l5);

        /* End of Outputs for SubSystem: '<S655>/If Action Subsystem' */
      } else if (rtb_LogicalOperator4) {
        /* Outputs for IfAction SubSystem: '<S655>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S661>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem((CATDefault_DataStore()),
          &rtb_Merge_l5);

        /* End of Outputs for SubSystem: '<S655>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S655>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S662>/Action Port'
         */
        BaseEngineController_LS_IfActionSubsystem
          (BaseEngineController_LS_B.s664_motohawk_interpolation_1d,
           &rtb_Merge_l5);

        /* End of Outputs for SubSystem: '<S655>/If Action Subsystem2' */
      }

      /* End of If: '<S655>/If' */

      /* Sum: '<S665>/Sum1' incorporates:
       *  Constant: '<S665>/Constant'
       *  Product: '<S665>/Product'
       *  Product: '<S665>/Product1'
       *  Sum: '<S665>/Sum'
       *  UnitDelay: '<S665>/Unit Delay'
       */
      rtb_Sum1_lf = (1.0 - rtb_Product_d0) *
        BaseEngineController_LS_DWork.s665_UnitDelay_DSTATE + rtb_Merge_l5 *
        rtb_Product_d0;

      /* If: '<S663>/If' incorporates:
       *  Inport: '<S666>/In1'
       *  Inport: '<S667>/In1'
       *  S-Function (motohawk_sfun_calibration): '<S663>/new_value'
       *  S-Function (motohawk_sfun_calibration): '<S663>/override_enable'
       */
      if ((CAT_ovr_DataStore())) {
        /* Outputs for IfAction SubSystem: '<S663>/NewValue' incorporates:
         *  ActionPort: '<S666>/Action Port'
         */
        BaseEngineController_LS_B.s663_Merge = (CAT_new_DataStore());

        /* End of Outputs for SubSystem: '<S663>/NewValue' */
      } else {
        /* Outputs for IfAction SubSystem: '<S663>/OldValue' incorporates:
         *  ActionPort: '<S667>/Action Port'
         */
        BaseEngineController_LS_B.s663_Merge = rtb_Sum1_lf;

        /* End of Outputs for SubSystem: '<S663>/OldValue' */
      }

      /* End of If: '<S663>/If' */

      /* Logic: '<S655>/Logical Operator2' incorporates:
       *  RelationalOperator: '<S655>/Relational Operator2'
       *  S-Function (motohawk_sfun_calibration): '<S655>/motohawk_calibration1'
       *  S-Function (motohawk_sfun_data_read): '<S655>/motohawk_data_read1'
       */
      rtb_LogicalOperator2_i = ((MPRD_DataStore() && (rtb_DataTypeConversion_i >
                                  (CATMax_DataStore()))));

      /* S-Function (motohawk_sfun_fault_def): '<S655>/motohawk_fault_def2' */

      /* Set Fault Suspected Status: CATRangeHigh */
      {
        extern void SetFaultSuspected(uint32_T fault, boolean_T val);
        extern void UpdateFault(uint32_T fault);
        SetFaultSuspected(25, rtb_LogicalOperator2_i);
        UpdateFault(25);
      }

      /* Logic: '<S655>/Logical Operator3' incorporates:
       *  RelationalOperator: '<S655>/Relational Operator3'
       *  S-Function (motohawk_sfun_calibration): '<S655>/motohawk_calibration6'
       *  S-Function (motohawk_sfun_data_read): '<S655>/motohawk_data_read1'
       */
      rtb_LogicalOperator3_p = ((MPRD_DataStore() && (rtb_DataTypeConversion_i <
                                  (CATMin_DataStore()))));

      /* S-Function (motohawk_sfun_fault_def): '<S655>/motohawk_fault_def3' */

      /* Set Fault Suspected Status: CATRangeLow */
      {
        extern void SetFaultSuspected(uint32_T fault, boolean_T val);
        extern void UpdateFault(uint32_T fault);
        SetFaultSuspected(26, rtb_LogicalOperator3_p);
        UpdateFault(26);
      }

      /* Update for UnitDelay: '<S656>/Unit Delay' */
      BaseEngineController_LS_DWork.s656_UnitDelay_DSTATE =
        BaseEngineController_LS_B.s656_Merge;

      /* Update for UnitDelay: '<S674>/Unit Delay' */
      BaseEngineController_LS_DWork.s674_UnitDelay_DSTATE = rtb_Sum1_h;

      /* Update for UnitDelay: '<S658>/Unit Delay' */
      BaseEngineController_LS_DWork.s658_UnitDelay_DSTATE =
        BaseEngineController_LS_B.s658_Merge;

      /* Update for UnitDelay: '<S692>/Unit Delay' */
      BaseEngineController_LS_DWork.s692_UnitDelay_DSTATE = rtb_Sum1_hn;

      /* Update for UnitDelay: '<S657>/Unit Delay' */
      BaseEngineController_LS_DWork.s657_UnitDelay_DSTATE = rtb_Merge_l;

      /* Update for UnitDelay: '<S683>/Unit Delay' */
      BaseEngineController_LS_DWork.s683_UnitDelay_DSTATE = rtb_Sum1_g;

      /* Update for UnitDelay: '<S655>/Unit Delay' */
      BaseEngineController_LS_DWork.s655_UnitDelay_DSTATE = rtb_Merge_l5;

      /* Update for UnitDelay: '<S665>/Unit Delay' */
      BaseEngineController_LS_DWork.s665_UnitDelay_DSTATE = rtb_Sum1_lf;
    }
  }
}
