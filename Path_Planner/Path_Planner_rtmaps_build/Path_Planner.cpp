/*
 * Path_Planner.cpp
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

#include "Path_Planner.h"
#include "rtwtypes.h"
#include <cstring>

/* External inputs (root inport signals with default storage) */
ExtU_Path_Planner_T Path_Planner_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Path_Planner_T Path_Planner_Y;

/* Real-time model */
RT_MODEL_Path_Planner_T Path_Planner_M_{ };

RT_MODEL_Path_Planner_T *const Path_Planner_M{ &Path_Planner_M_ };

/* Model step function */
void Path_Planner_step(void)
{
  /* Outport: '<Root>/TrgtSpd_kmph' incorporates:
   *  Inport: '<Root>/SetSpeed_kmph'
   */
  Path_Planner_Y.TrgtSpd_kmph = Path_Planner_U.SetSpeed_kmph;

  /* Outport: '<Root>/RelDist_m' incorporates:
   *  Inport: '<Root>/LdCrLongDist_m'
   */
  Path_Planner_Y.RelDist_m = Path_Planner_U.LdCrLongDist_m;

  /* Outport: '<Root>/RelSpd_kmph' incorporates:
   *  Inport: '<Root>/LdCrLongSpd_kmph'
   */
  Path_Planner_Y.RelSpd_kmph = Path_Planner_U.LdCrLongSpd_kmph;

  /* If: '<Root>/If' incorporates:
   *  Constant: '<Root>/cacc_override_dist_m'
   *  If: '<Root>/If1'
   */
  if (Path_Planner_P.cacc_override_dist_m_Value == -1.0) {
    /* Outport: '<Root>/IntdToStp_bool' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Gain: '<S5>/Gain'
     *  Inport: '<Root>/LdCrLongSpd_kmph'
     *  Inport: '<Root>/VehSpdAvrgDrvn_kmph'
     *  RelationalOperator: '<S5>/Equal1'
     */
    Path_Planner_Y.IntdToStp_bool = (Path_Planner_P.Gain_Gain *
      Path_Planner_U.VehSpdAvrgDrvn_kmph == Path_Planner_U.LdCrLongSpd_kmph);

    /* Outport: '<Root>/TrgtDist_m' */
    Path_Planner_Y.TrgtDist_m = Path_Planner_P.cacc_override_dist_m_Value;
  } else {
    /* Outport: '<Root>/IntdToStp_bool' incorporates:
     *  Constant: '<S4>/Constant'
     */
    Path_Planner_Y.IntdToStp_bool = Path_Planner_P.Constant_Value;

    /* Outport: '<Root>/TrgtDist_m' incorporates:
     *  Constant: '<Root>/cacc_dist_offset_m'
     *  Constant: '<Root>/cacc_time_gap_sec'
     *  Gain: '<S6>/kmph_mps_converter'
     *  Inport: '<Root>/LdCrLongSpd_kmph'
     *  Inport: '<Root>/VehSpdAvrgDrvn_kmph'
     *  Product: '<S6>/Product'
     *  Sum: '<S6>/Add'
     *  Sum: '<S6>/Add1'
     */
    Path_Planner_Y.TrgtDist_m = (Path_Planner_U.VehSpdAvrgDrvn_kmph +
      Path_Planner_U.LdCrLongSpd_kmph) * Path_Planner_P.kmph_mps_converter_Gain *
      Path_Planner_P.cacc_time_gap_sec_Value +
      Path_Planner_P.cacc_dist_offset_m_Value;
  }

  /* End of If: '<Root>/If' */
}

/* Model initialize function */
void Path_Planner_initialize(void)
{
  /* Registration code */

  /* external inputs */
  (void)std::memset(&Path_Planner_U, 0, sizeof(ExtU_Path_Planner_T));

  /* external outputs */
  (void)std::memset(&Path_Planner_Y, 0, sizeof(ExtY_Path_Planner_T));
}

/* Model terminate function */
void Path_Planner_terminate(void)
{
  /* (no terminate code required) */
}
