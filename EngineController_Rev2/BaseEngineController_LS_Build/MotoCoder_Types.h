
/* MotoCoder_Types.h */
/* Generated by MotoCoder */
/* Version: 0.12.4 */
/* At: 2020-10-04 18:31:02 */
/* Copyright: 2020 Woodward. */


#ifndef MOTOCODER_TYPES_H
#define MOTOCODER_TYPES_H



	


/* reference_T used as a pointer to DataStorage */
#ifndef defined_reference_T
#define defined_reference_T
typedef void * reference_T;
#endif

/* struct_reference_T used as a pointer to Structure DataStorage */
#ifndef defined_struct_reference_T
#define defined_struct_reference_T
typedef void * struct_reference_T;
#endif

#ifndef defined_char_T
#define defined_char_T
typedef char                   char_T;
#endif

#ifndef defined_boolean_T
#define defined_boolean_T
typedef unsigned char          boolean_T;
#endif

#ifndef defined_int8_T
#define defined_int8_T
typedef signed char            int8_T;
#endif

#ifndef defined_uint8_T
#define defined_uint8_T
typedef unsigned char          uint8_T;
#endif

#ifndef defined_int16_T
#define defined_int16_T
typedef short                  int16_T;
#endif

#ifndef defined_uint16_T
#define defined_uint16_T
typedef unsigned short         uint16_T;
#endif

#ifndef defined_int32_T
#define defined_int32_T
typedef int                    int32_T;
#endif

#ifndef defined_uint32_T
#define defined_uint32_T
typedef unsigned int           uint32_T;
#endif

#ifndef defined_int64_T
#define defined_int64_T
typedef long long              int64_T;
#endif

#ifndef defined_uint64_T
#define defined_uint64_T
typedef unsigned long long     uint64_T;
#endif

#ifndef defined_real32_T
#define defined_real32_T
typedef float                  real32_T;
#endif

#ifndef defined_real64_T
#define defined_real64_T
typedef double                 real64_T;
#endif

#define Interrupt_Disable() DISABLE()
#define Interrupt_Enable() UNDISABLE()
    /* S_CCPDAQ structure */
typedef struct {
    uint32_T   TxID;
    uint16_T   Prescaler;
    uint8_T   DAQStatus;
    uint8_T   LastODTNumber;
    uint8_T   EventChannelNumber;
} S_CCPDAQ_T;

/* S_CCPODTItem structure */
typedef struct {
    reference_T   pData;
    uint8_T   DataSize;
} S_CCPODTItem_T;

/* S_CCPODT structure */
typedef struct {
    uint8_T   ODTSize;
    S_CCPODTItem_T   ODTList[7];
} S_CCPODT_T;

/* S_ConstFault structure */
typedef struct {
    uint16_T   mode;
    uint16_T   id;
    uint16_T   test;
    uint16_T   xlim;
    uint16_T   ylim;
    uint16_T   action1;
    uint16_T   action1_condition;
    uint16_T   action2;
    uint16_T   action2_condition;
    uint16_T   action3;
    uint16_T   action3_condition;
    uint16_T   action4;
    uint16_T   action4_condition;
} S_ConstFault_T;

/* S_Fault structure */
typedef struct {
    uint16_T   x;
    uint16_T   y;
} S_Fault_T;

/* S_FaultAction structure */
typedef struct {
    uint8_T   reference_count;
} S_FaultAction_T;

/* S_FaultManager structure */
typedef struct {
    uint8_T   suspected[15];
    uint8_T   active[15];
    uint8_T   occurred[15];
    uint8_T   last_suspected_fault;
    uint8_T   last_unsuspected_fault;
    uint8_T   last_active_fault;
    uint8_T   last_inactive_fault;
    uint8_T   last_occurred_fault;
} S_FaultManager_T;

/* S_DispFaultManager structure */
typedef struct {
    uint8_T   current_suspected_vardec;
    uint8_T   current_active_vardec;
    uint8_T   current_occurred_vardec;
} S_DispFaultManager_T;

/* S_ConstFaultManager structure */
typedef struct {
    uint8_T   num_faults;
    uint16_T   num_actions;
} S_ConstFaultManager_T;

/* FaultActions Enumeration */
typedef enum {
    FAULTACTIONS_CUTTHROTTLE=0,
    FAULTACTIONS_DFCODISABLE=1,
    FAULTACTIONS_MIL_LED=10,
    FAULTACTIONS_MEDIUMREVLIMIT=11,
    FAULTACTIONS_SOFTREVLIMIT=12,
    FAULTACTIONS_OPENPARENNONECLOSEPAREN=13,
    FAULTACTIONS_DELAYEDENGINESHUTDOWN=2,
    FAULTACTIONS_DISABLEAC=3,
    FAULTACTIONS_DISABLEO2CTRL=4,
    FAULTACTIONS_DISABLEVEADAPT=5,
    FAULTACTIONS_DISABLEWASTEGATE=6,
    FAULTACTIONS_ENGINEPROTECTLED=7,
    FAULTACTIONS_ENGINESHUTDOWN=8,
    FAULTACTIONS_HARDREVLIMIT=9,
} E_FaultActions;

/* FaultDisp Enumeration */
typedef enum {
    FAULTDISP_CURRENTSUSPECTED=0,
    FAULTDISP_CURRENTACTIVE=1,
    FAULTDISP_CURRENTOCCURRED=2,
} E_FaultDisp;

/* Fault_Cols Enumeration */
typedef enum {
    FAULT_COLS_MODE=0,
    FAULT_COLS_ID=1,
    FAULT_COLS_ACTION3CONDITION=10,
    FAULT_COLS_ACTION4=11,
    FAULT_COLS_ACTION4CONDITION=12,
    FAULT_COLS_TEST=2,
    FAULT_COLS_FAULTYSAMPLESOPENPARENXCLOSEPAREN=3,
    FAULT_COLS_TOTALSAMPLESOPENPARENYCLOSEPAREN=4,
    FAULT_COLS_ACTION1=5,
    FAULT_COLS_ACTION1CONDITION=6,
    FAULT_COLS_ACTION2=7,
    FAULT_COLS_ACTION2CONDITION=8,
    FAULT_COLS_ACTION3=9,
} E_Fault_Cols;

/* Fault_Command Enumeration */
typedef enum {
    FAULT_COMMAND_DASH=0,
    FAULT_COMMAND_CLEARALLFAULTS=1,
} E_Fault_Command;

/* Fault_Cond Enumeration */
typedef enum {
    FAULT_COND_OPENPARENNONECLOSEPAREN=0,
    FAULT_COND_SUSPECTED=1,
    FAULT_COND_ACTIVE=2,
    FAULT_COND_SUSPECTEDORACTIVE=3,
    FAULT_COND_OCCURRED=4,
    FAULT_COND_SUSPECTEDOROCCURRED=5,
    FAULT_COND_ACTIVEOROCCURRED=6,
    FAULT_COND_SUSPECTEDORACTIVEOROCCURRED=7,
} E_Fault_Cond;

/* Fault_Mode Enumeration */
typedef enum {
    FAULT_MODE_DISABLED=0,
    FAULT_MODE_ENABLED=1,
    FAULT_MODE_STICKY=2,
    FAULT_MODE_ENABLEDDASHPERSISTENT=3,
    FAULT_MODE_STICKYDASHPERSISTENT=4,
    FAULT_MODE_SAVEOCCURRED=5,
} E_Fault_Mode;

/* Fault_Test Enumeration */
typedef enum {
    FAULT_TEST_DASH=0,
    FAULT_TEST_TEST=1,
} E_Fault_Test;

/* Faults Enumeration */
typedef enum {
    FAULTS_ACCHARGEHIGH_FAULT=0,
    FAULTS_ACCHARGELOW_FAULT=1,
    FAULTS_APP1_ADAPTRANGEHIGH=10,
    FAULTS_SOFTOVERSPEED=100,
    FAULTS_SYSVOLTRANGEHIGH=101,
    FAULTS_SYSVOLTRANGELOW=102,
    FAULTS_TPS1ADAPTHIMAX=103,
    FAULTS_TPS1ADAPTHIMIN=104,
    FAULTS_TPS1ADAPTLOMAX=105,
    FAULTS_TPS1ADAPTLOMIN=106,
    FAULTS_TPS1RANGEHIGH=107,
    FAULTS_TPS1RANGELOW=108,
    FAULTS_TPS2ADAPTHIMAX=109,
    FAULTS_APP1_ADAPTRANGELOW=11,
    FAULTS_TPS2ADAPTHIMIN=110,
    FAULTS_TPS2ADAPTLOMAX=111,
    FAULTS_TPS2ADAPTLOMIN=112,
    FAULTS_TPS2RANGEHIGH=113,
    FAULTS_TPS2RANGELOW=114,
    FAULTS_TPS_SENSORS_CONFLICT=115,
    FAULTS_VSPDRANGEHIGH=116,
    FAULTS_VSPDRANGELOW=117,
    FAULTS_WASTEGATE_FAULT=118,
    FAULTS_OPENPARENNONECLOSEPAREN=119,
    FAULTS_APP2RANGEHIGH=12,
    FAULTS_APP2RANGELOW=13,
    FAULTS_APP2_ADAPTADAPTHIMAX=14,
    FAULTS_APP2_ADAPTADAPTHIMIN=15,
    FAULTS_APP2_ADAPTADAPTLOMAX=16,
    FAULTS_APP2_ADAPTADAPTLOMIN=17,
    FAULTS_APP2_ADAPTRANGEHIGH=18,
    FAULTS_APP2_ADAPTRANGELOW=19,
    FAULTS_ACPRESRANGEHIGH=2,
    FAULTS_APP_SENSORS_CONFLICT=20,
    FAULTS_BANK1_EQUIVRATIORANGEHIGH=21,
    FAULTS_BANK1_EQUIVRATIORANGELOW=22,
    FAULTS_BANK2_EQUIVRATIORANGEHIGH=23,
    FAULTS_BANK2_EQUIVRATIORANGELOW=24,
    FAULTS_CATRANGEHIGH=25,
    FAULTS_CATRANGELOW=26,
    FAULTS_CAMEDGESFAULT=27,
    FAULTS_CAMSYNCFAULT=28,
    FAULTS_CRANKEDGESFAULT=29,
    FAULTS_ACPRESRANGELOW=3,
    FAULTS_CRANKSYNCFAULT=30,
    FAULTS_ECTOVERTEMPFAULT=31,
    FAULTS_ECTRANGEHIGH=32,
    FAULTS_ECTRANGELOW=33,
    FAULTS_ECTSEVEREOVERTEMPFAULT=34,
    FAULTS_EST1_OPEN=35,
    FAULTS_EST1_SHORT=36,
    FAULTS_EST2_OPEN=37,
    FAULTS_EST2_SHORT=38,
    FAULTS_EST3_OPEN=39,
    FAULTS_APP1RANGEHIGH=4,
    FAULTS_EST3_SHORT=40,
    FAULTS_EST4_OPEN=41,
    FAULTS_EST4_SHORT=42,
    FAULTS_EST5_OPEN=43,
    FAULTS_EST5_SHORT=44,
    FAULTS_EST6_OPEN=45,
    FAULTS_EST6_SHORT=46,
    FAULTS_EST7_OPEN=47,
    FAULTS_EST7_SHORT=48,
    FAULTS_EST8_OPEN=49,
    FAULTS_APP1RANGELOW=5,
    FAULTS_EST8_SHORT=50,
    FAULTS_ETCSPRINGTEST=51,
    FAULTS_ETC_OPEN_FAULT=52,
    FAULTS_ETC_STICKING=53,
    FAULTS_EVAPRANGEHIGH=54,
    FAULTS_EVAPRANGELOW=55,
    FAULTS_FUELADAPTRANGEHI=56,
    FAULTS_FUELADAPTRANGELOW=57,
    FAULTS_FUELPRESHIGH_FAULT=58,
    FAULTS_FUELPRESLOW_FAULT=59,
    FAULTS_APP1_ADAPTADAPTHIMAX=6,
    FAULTS_FUELPRESRANGEHIGH=60,
    FAULTS_FUELPRESRANGELOW=61,
    FAULTS_FUELSENSRANGEHIGH=62,
    FAULTS_FUELSENSRANGELOW=63,
    FAULTS_HARDOVERBOOST_FAULT=64,
    FAULTS_HARDOVERSPEED=65,
    FAULTS_IATRANGEHIGH=66,
    FAULTS_IATRANGELOW=67,
    FAULTS_INJ1OPEN=68,
    FAULTS_INJ2OPEN=69,
    FAULTS_APP1_ADAPTADAPTHIMIN=7,
    FAULTS_INJ3OPEN=70,
    FAULTS_INJ4OPEN=71,
    FAULTS_INJ5OPEN=72,
    FAULTS_INJ6OPEN=73,
    FAULTS_INJ7OPEN=74,
    FAULTS_INJ8OPEN=75,
    FAULTS_LAMBDA_1_NOTREADY=76,
    FAULTS_LAMBDA_1_TIMEOUT=77,
    FAULTS_LAMBDA_2_NOTREADY=78,
    FAULTS_LAMBDA_2_TIMEOUT=79,
    FAULTS_APP1_ADAPTADAPTLOMAX=8,
    FAULTS_LEANPROTECT_FAULT=80,
    FAULTS_MAFRANGEHIGH=81,
    FAULTS_MAFRANGELOW=82,
    FAULTS_MAPRANGEHIGH=83,
    FAULTS_MAPRANGELOW=84,
    FAULTS_MAPTIMERANGEHIGH=85,
    FAULTS_MAPTIMERANGELOW=86,
    FAULTS_MAP_IR_HI=87,
    FAULTS_MAP_IR_LO=88,
    FAULTS_MAP_STICKING=89,
    FAULTS_APP1_ADAPTADAPTLOMIN=9,
    FAULTS_MEDIUMOVERSPEED=90,
    FAULTS_NOOIL_FAULT=91,
    FAULTS_O2FAILEDLEAN=92,
    FAULTS_O2FAILEDRICH=93,
    FAULTS_O2NOTACTIVE=94,
    FAULTS_OILPRESRANGEHIGH=95,
    FAULTS_OILPRESRANGELOW=96,
    FAULTS_SENSVOLTRANGEHIGH=97,
    FAULTS_SENSVOLTRANGELOW=98,
    FAULTS_SOFTOVERBOOST_FAULT=99,
} E_Faults;

/* VarDecEnum_1 Enumeration */
typedef enum {
    VARDECENUM_1_PASSDASHTHROUGH=0,
    VARDECENUM_1_OVERRIDE=1,
} E_VarDecEnum_1;

/* VarDecEnum_10 Enumeration */
typedef enum {
    VARDECENUM_10_APP1=0,
    VARDECENUM_10_NORMAL=1,
} E_VarDecEnum_10;

/* VarDecEnum_15 Enumeration */
typedef enum {
    VARDECENUM_15_GOVENABLED=0,
    VARDECENUM_15_GOVDISABLED=1,
} E_VarDecEnum_15;

/* VarDecEnum_19 Enumeration */
typedef enum {
    VARDECENUM_19_ETC=0,
    VARDECENUM_19_IAC=1,
} E_VarDecEnum_19;

/* VarDecEnum_2 Enumeration */
typedef enum {
    VARDECENUM_2_RUN=0,
    VARDECENUM_2_REBOOT=1,
} E_VarDecEnum_2;

/* VarDecEnum_20 Enumeration */
typedef enum {
    VARDECENUM_20_2DASHWIRE=0,
    VARDECENUM_20_3DASHWIRE=1,
} E_VarDecEnum_20;

/* VarDecEnum_21 Enumeration */
typedef enum {
    VARDECENUM_21_PWM=0,
    VARDECENUM_21_ONOFF=1,
} E_VarDecEnum_21;

/* VarDecEnum_24 Enumeration */
typedef enum {
    VARDECENUM_24_RATELIMITER=0,
    VARDECENUM_24_LOWPASS=1,
    VARDECENUM_24_MOVINGAVERAGE=2,
} E_VarDecEnum_24;

/* VarDecEnum_25 Enumeration */
typedef enum {
    VARDECENUM_25_MODELFROMMAP=0,
    VARDECENUM_25_USEMAFSENSORDIRECTLY=1,
} E_VarDecEnum_25;

/* VarDecEnum_26 Enumeration */
typedef enum {
    VARDECENUM_26_CUTSPARK=0,
    VARDECENUM_26_CUTFUEL=1,
    VARDECENUM_26_CUTSPARKANDFUEL=2,
} E_VarDecEnum_26;

/* VarDecEnum_3 Enumeration */
typedef enum {
    VARDECENUM_3_OFF=0,
    VARDECENUM_3_ON=1,
} E_VarDecEnum_3;

/* VarDecEnum_30 Enumeration */
typedef enum {
    VARDECENUM_30_DASH=0,
    VARDECENUM_30_STALL=1,
    VARDECENUM_30_CRANK=2,
    VARDECENUM_30_RUN=3,
} E_VarDecEnum_30;

/* VarDecEnum_34 Enumeration */
typedef enum {
    VARDECENUM_34_RISINGEDGE=0,
    VARDECENUM_34_FALLINGEDGE=1,
} E_VarDecEnum_34;

/* VarDecEnum_35 Enumeration */
typedef enum {
    VARDECENUM_35_WEAKPULLUP=0,
    VARDECENUM_35_STRONGPULLUP=1,
} E_VarDecEnum_35;

/* VarDecEnum_36 Enumeration */
typedef enum {
    VARDECENUM_36_OPENPARENNONECLOSEPAREN=-1,
    VARDECENUM_36_EST1=36,
    VARDECENUM_36_EST2=37,
    VARDECENUM_36_EST3=38,
    VARDECENUM_36_EST4=39,
    VARDECENUM_36_EST5=40,
    VARDECENUM_36_EST6=41,
    VARDECENUM_36_EST7=42,
    VARDECENUM_36_EST8=43,
} E_VarDecEnum_36;

/* VarDecEnum_37 Enumeration */
typedef enum {
    VARDECENUM_37_STANDARDOPENPARENCOILPERCYLINDERCLOSEPAREN=0,
    VARDECENUM_37_BANKEDOPENPARENFIREONBOTHPHASESUNTILCAMSYNCCLOSEPAREN=1,
    VARDECENUM_37_BATCHOPENPARENWASTEDSPARKCLOSEPAREN=2,
    VARDECENUM_37_MUXEDOPENPARENDISTRIBUTEDCLOSEPAREN=3,
} E_VarDecEnum_37;

/* VarDecEnum_38 Enumeration */
typedef enum {
    VARDECENUM_38_OPENPARENNONECLOSEPAREN=-1,
    VARDECENUM_38_FINJ1=12,
    VARDECENUM_38_AINJ4=21,
    VARDECENUM_38_AINJ5=22,
    VARDECENUM_38_AINJ6=23,
    VARDECENUM_38_FINJ2=13,
    VARDECENUM_38_FINJ3=14,
    VARDECENUM_38_FINJ4=15,
    VARDECENUM_38_FINJ5=16,
    VARDECENUM_38_FINJ6=17,
    VARDECENUM_38_AINJ1=18,
    VARDECENUM_38_AINJ2=19,
    VARDECENUM_38_AINJ3=20,
} E_VarDecEnum_38;

/* VarDecEnum_39 Enumeration */
typedef enum {
    VARDECENUM_39_STANDARDOPENPARENINJECTORPERCYLINDERCLOSEPAREN=0,
    VARDECENUM_39_BATCHOPENPARENFIREHALFFUELONHALFOFTHEINJECTORSEVERYREVCLOSEPAREN=1,
    VARDECENUM_39_WASTEDOPENPARENFIREHALFFUELONALLINJECTORSEVERYREVCLOSEPAREN=2,
} E_VarDecEnum_39;

/* VarDecEnum_4 Enumeration */
typedef enum {
    VARDECENUM_4_DISABLED=0,
    VARDECENUM_4_ENABLED=1,
} E_VarDecEnum_4;

/* VarDecEnum_40 Enumeration */
typedef enum {
    VARDECENUM_40_STANDARD=0,
    VARDECENUM_40_TRANSIENT=1,
} E_VarDecEnum_40;

/* VarDecEnum_42 Enumeration */
typedef enum {
    VARDECENUM_42_CUTTHROTTLE=0,
    VARDECENUM_42_DFCODISABLE=1,
    VARDECENUM_42_MIL_LED=10,
    VARDECENUM_42_MEDIUMREVLIMIT=11,
    VARDECENUM_42_SOFTREVLIMIT=12,
    VARDECENUM_42_DELAYEDENGINESHUTDOWN=2,
    VARDECENUM_42_DISABLEAC=3,
    VARDECENUM_42_DISABLEO2CTRL=4,
    VARDECENUM_42_DISABLEVEADAPT=5,
    VARDECENUM_42_DISABLEWASTEGATE=6,
    VARDECENUM_42_ENGINEPROTECTLED=7,
    VARDECENUM_42_ENGINESHUTDOWN=8,
    VARDECENUM_42_HARDREVLIMIT=9,
} E_VarDecEnum_42;

/* VarDecEnum_43 Enumeration */
typedef enum {
    VARDECENUM_43_DASH=0,
} E_VarDecEnum_43;

/* VarDecEnum_44 Enumeration */
typedef enum {
    VARDECENUM_44_OPENPARENNONECLOSEPAREN=-1,
    VARDECENUM_44_ECUP=53,
    VARDECENUM_44_AN7M=62,
    VARDECENUM_44_AN8M=63,
    VARDECENUM_44_AN9M=64,
    VARDECENUM_44_AN10M=65,
    VARDECENUM_44_AN11M=66,
    VARDECENUM_44_AN12M=67,
    VARDECENUM_44_AN13M=68,
    VARDECENUM_44_AN14M=69,
    VARDECENUM_44_AN15M=70,
    VARDECENUM_44_AN16M=71,
    VARDECENUM_44_DRVP=54,
    VARDECENUM_44_AN17M=72,
    VARDECENUM_44_AN18M=73,
    VARDECENUM_44_AN19M=74,
    VARDECENUM_44_O2A=90,
    VARDECENUM_44_O2B=91,
    VARDECENUM_44_XDRP_B=92,
    VARDECENUM_44_XDRP=55,
    VARDECENUM_44_AN1M=56,
    VARDECENUM_44_AN2M=57,
    VARDECENUM_44_AN3M=58,
    VARDECENUM_44_AN4M=59,
    VARDECENUM_44_AN5M=60,
    VARDECENUM_44_AN6M=61,
} E_VarDecEnum_44;

/* VarDecEnum_45 Enumeration */
typedef enum {
    VARDECENUM_45_5V=0,
    VARDECENUM_45_2POINT7V=1,
} E_VarDecEnum_45;

/* VarDecEnum_46 Enumeration */
typedef enum {
    VARDECENUM_46_OPENPARENNONECLOSEPAREN=-1,
    VARDECENUM_46_FUELP=0,
    VARDECENUM_46_FINJ3=14,
    VARDECENUM_46_FINJ4=15,
    VARDECENUM_46_FINJ5=16,
    VARDECENUM_46_FINJ6=17,
    VARDECENUM_46_AINJ1=18,
    VARDECENUM_46_AINJ2=19,
    VARDECENUM_46_AINJ3=20,
    VARDECENUM_46_AINJ4=21,
    VARDECENUM_46_AINJ5=22,
    VARDECENUM_46_AINJ6=23,
    VARDECENUM_46_HSOL1=2,
    VARDECENUM_46_TACH=24,
    VARDECENUM_46_EST1=36,
    VARDECENUM_46_EST2=37,
    VARDECENUM_46_EST3=38,
    VARDECENUM_46_EST4=39,
    VARDECENUM_46_EST5=40,
    VARDECENUM_46_EST6=41,
    VARDECENUM_46_EST7=42,
    VARDECENUM_46_EST8=43,
    VARDECENUM_46_MPRD=52,
    VARDECENUM_46_HSOL2=3,
    VARDECENUM_46_HSOL3=4,
    VARDECENUM_46_HSOL4=5,
    VARDECENUM_46_START=6,
    VARDECENUM_46_OILP=11,
    VARDECENUM_46_FINJ1=12,
    VARDECENUM_46_FINJ2=13,
} E_VarDecEnum_46;

/* VarDecEnum_47 Enumeration */
typedef enum {
    VARDECENUM_47_OPENPARENNONECLOSEPAREN=-1,
    VARDECENUM_47_DG1M=93,
    VARDECENUM_47_DG2M=94,
    VARDECENUM_47_DG4M=96,
    VARDECENUM_47_CNK=100,
} E_VarDecEnum_47;

/* VarDecEnum_48 Enumeration */
typedef enum {
    VARDECENUM_48_NOALIASPROTECT=0,
    VARDECENUM_48_USEALIASPROTECT=1,
} E_VarDecEnum_48;

/* VarDecEnum_49 Enumeration */
typedef enum {
    VARDECENUM_49_DIGITALINPUT=0,
    VARDECENUM_49_VRINPUT=1,
} E_VarDecEnum_49;

/* VarDecEnum_5 Enumeration */
typedef enum {
    VARDECENUM_5_RUN=0,
    VARDECENUM_5_RESTORETODEFAULTS=1,
} E_VarDecEnum_5;

/* VarDecEnum_50 Enumeration */
typedef enum {
    VARDECENUM_50_OPENPARENNONECLOSEPAREN=-1,
    VARDECENUM_50_AN1M=56,
    VARDECENUM_50_AN10M=65,
    VARDECENUM_50_AN11M=66,
    VARDECENUM_50_AN12M=67,
    VARDECENUM_50_AN13M=68,
    VARDECENUM_50_AN14M=69,
    VARDECENUM_50_AN15M=70,
    VARDECENUM_50_AN16M=71,
    VARDECENUM_50_AN17M=72,
    VARDECENUM_50_AN18M=73,
    VARDECENUM_50_AN19M=74,
    VARDECENUM_50_AN2M=57,
    VARDECENUM_50_O2A=90,
    VARDECENUM_50_O2B=91,
    VARDECENUM_50_DG1M=93,
    VARDECENUM_50_DG2M=94,
    VARDECENUM_50_DG4M=96,
    VARDECENUM_50_ESTOP=97,
    VARDECENUM_50_AN3M=58,
    VARDECENUM_50_AN4M=59,
    VARDECENUM_50_AN5M=60,
    VARDECENUM_50_AN6M=61,
    VARDECENUM_50_AN7M=62,
    VARDECENUM_50_AN8M=63,
    VARDECENUM_50_AN9M=64,
} E_VarDecEnum_50;

/* VarDecEnum_51 Enumeration */
typedef enum {
    VARDECENUM_51_OPENPARENNONECLOSEPAREN=-1,
    VARDECENUM_51_FUELP=0,
    VARDECENUM_51_FINJ2=13,
    VARDECENUM_51_FINJ3=14,
    VARDECENUM_51_FINJ4=15,
    VARDECENUM_51_FINJ5=16,
    VARDECENUM_51_FINJ6=17,
    VARDECENUM_51_AINJ1=18,
    VARDECENUM_51_AINJ2=19,
    VARDECENUM_51_AINJ3=20,
    VARDECENUM_51_AINJ4=21,
    VARDECENUM_51_AINJ5=22,
    VARDECENUM_51_ETC=1,
    VARDECENUM_51_AINJ6=23,
    VARDECENUM_51_TACH=24,
    VARDECENUM_51_EST1=36,
    VARDECENUM_51_EST2=37,
    VARDECENUM_51_EST3=38,
    VARDECENUM_51_EST4=39,
    VARDECENUM_51_EST5=40,
    VARDECENUM_51_EST6=41,
    VARDECENUM_51_EST7=42,
    VARDECENUM_51_EST8=43,
    VARDECENUM_51_HSOL1=2,
    VARDECENUM_51_HSOL2=3,
    VARDECENUM_51_HSOL3=4,
    VARDECENUM_51_HSOL4=5,
    VARDECENUM_51_START=6,
    VARDECENUM_51_OILP=11,
    VARDECENUM_51_FINJ1=12,
} E_VarDecEnum_51;

/* VarDecEnum_6 Enumeration */
typedef enum {
    VARDECENUM_6_RUN=0,
    VARDECENUM_6_STORETOEEPROM=1,
} E_VarDecEnum_6;

/* VarDecEnum_7 Enumeration */
typedef enum {
    VARDECENUM_7_FALSE=0,
    VARDECENUM_7_TRUE=1,
} E_VarDecEnum_7;

/* VarDecEnum_8 Enumeration */
typedef enum {
    VARDECENUM_8_ENABLE=0,
    VARDECENUM_8_CUT=1,
} E_VarDecEnum_8;

/* VarDecEnum_9 Enumeration */
typedef enum {
    VARDECENUM_9_UNLOCKED=0,
    VARDECENUM_9_LOCKED=1,
} E_VarDecEnum_9;



#endif

