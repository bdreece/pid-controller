/*! \file d_cntl.h
 *  \brief Derivative Controller
 */

#ifndef D_CNTL_H
#define D_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pid_conf.h"

extern void clamp(unit_t *cv);

/*! \brief Derivative Controller Handle
 *
 *  Structure to handle configuration of a
 *  given instance of the derivative controller.
 */
typedef struct {
  unit_t kd;        //!< Derivative Gain
  unit_t last_err;  //!< Last error to track derivative difference
} d_cntl;

/*! \brief Initialize Derivative Controller
 *
 *  Assign derivative gain value, kd, to a
 *  derivative controller instance, cntl, and
 *  initialize last error value to zero.
 *
 *  \param cntl The derivative controller
 *  \param kd The derivative gain
 */
void d_init(d_cntl *cntl, unit_t kd);

/*! \brief Evaluate the Control Variable
 *
 *  Given a derivative controller and target,
 *  evaluate the control variable with respect
 *  to the current value. Dynamic clamping
 *  optional.
 *
 *  \param cntl The derivative controller
 *  \param target_val The target value
 *  \param current_val The current value
 *  \param clmp Whether to clamp the control variable, non-zero if desired
 *  \return The control variable
 */
unit_t d_eval(d_cntl *cntl, unit_t target_val, unit_t current_val, int clmp);

#ifdef __cplusplus
}
#endif

#endif // D_CNTL_H
