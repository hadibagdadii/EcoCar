/*
 * Path_Planner.h
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "Path_Planner".
 *
 * Model version              : 1.24
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C++ source code generated on : Sat Jan 18 21:50:46 2025
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Path_Planner_h_
#define RTW_HEADER_Path_Planner_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Path_Planner_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
struct ExtU_Path_Planner_T {
  real_T VehSpdAvrgDrvn_kmph;          /* '<Root>/VehSpdAvrgDrvn_kmph' */
  real_T SetSpeed_kmph;                /* '<Root>/SetSpeed_kmph' */
  real_T LdCrCount_num;                /* '<Root>/LdCrCount_num' */
  real_T LdCrLongDist_m;               /* '<Root>/LdCrLongDist_m' */
  real_T LdCrLongSpd_kmph;             /* '<Root>/LdCrLongSpd_kmph' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_Path_Planner_T {
  real_T TrgtSpd_kmph;                 /* '<Root>/TrgtSpd_kmph' */
  real_T RelDist_m;                    /* '<Root>/RelDist_m' */
  real_T RelSpd_kmph;                  /* '<Root>/RelSpd_kmph' */
  real_T IntdToStp_bool;               /* '<Root>/IntdToStp_bool' */
  real_T TrgtDist_m;                   /* '<Root>/TrgtDist_m' */
};

/* Parameters (default storage) */
struct P_Path_Planner_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T cacc_override_dist_m_Value;   /* Expression: -1
                                        * Referenced by: '<Root>/cacc_override_dist_m'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T cacc_dist_offset_m_Value;     /* Expression: 8
                                        * Referenced by: '<Root>/cacc_dist_offset_m'
                                        */
  real_T cacc_time_gap_sec_Value;      /* Expression: 3.0
                                        * Referenced by: '<Root>/cacc_time_gap_sec'
                                        */
  real_T kmph_mps_converter_Gain;      /* Expression: 1/3.6
                                        * Referenced by: '<S6>/kmph_mps_converter'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Path_Planner_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_Path_Planner_T Path_Planner_P;

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  /* External inputs (root inport signals with default storage) */
  extern struct ExtU_Path_Planner_T Path_Planner_U;

  /* External outputs (root outports fed by signals with default storage) */
  extern struct ExtY_Path_Planner_T Path_Planner_Y;

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void Path_Planner_initialize(void);
  extern void Path_Planner_step(void);
  extern void Path_Planner_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_Path_Planner_T *const Path_Planner_M;

#ifdef __cplusplus

}

#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Path_Planner'
 * '<S1>'   : 'Path_Planner/If Action Subsystem'
 * '<S2>'   : 'Path_Planner/If Action Subsystem1'
 * '<S3>'   : 'Path_Planner/If Action Subsystem3'
 * '<S4>'   : 'Path_Planner/If Action Subsystem4'
 * '<S5>'   : 'Path_Planner/Stop_Determination'
 * '<S6>'   : 'Path_Planner/Target_Distance_Calculation'
 */
#endif                                 /* RTW_HEADER_Path_Planner_h_ */
