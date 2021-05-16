/*! \file p_cntl.h
 *  \brief Proportional Controller
 */

#ifndef P_CNTL_H
#define P_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pid_conf.h"

extern void clamp(unit_t *cv);

/*! \brief Proportional Controller Handle
 *
 *  Structure to handle configuration of a
 *  given instance of the proportional
 *  controller.
 */
typedef struct {
  unit_t kp; //!< Proportional gain
} p_cntl;

/*! \brief Initialize Proportional Controller
 *
 *  Assigns the gain value, kp, to a given
 *  proportional controller, cntl.
 *
 *  \param cntl The proportional controller handle
 *  \param kp The proportional gain
 */
void p_init(p_cntl *cntl, unit_t kp);

/*! \brief Evaluate the control variable
 *
 *  Given a proportional controller and target,
 *  evaluate the control variable with respect
 *  to the current value. Dynamic clamping
 *  optional.
 *
 *  \param cntl The proportional controller
 *  \param target_val The target value
 *  \param current_val The current value
 *  \param clmp Whether to clamp control variable, non-zero if desired
 *  \return The control variable
 */
unit_t p_eval(p_cntl *cntl, unit_t target_val, unit_t current_val, int clmp);

#ifdef __cplusplus
}
#endif

#endif // P_CNTL_H
