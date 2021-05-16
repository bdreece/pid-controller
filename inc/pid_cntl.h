/*! \file pid_cntl.h
 *  \brief Proportional-Integral-Derivative Controller
 */

#ifndef PID_CNTL_H
#define PID_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "p_cntl.h"
#include "i_cntl.h"
#include "d_cntl.h"

extern void clamp(unit_t *cv);

/*! \brief Proportional-Integral-Derivative Controller Handle
 *
 *  Structure to handle configuration for a
 *  given instance of the proportional-integral-derivative
 *  controller.
 */
typedef struct {
  p_cntl p;  //!< Proportional controller
  i_cntl i;  //!< Integral controller
  d_cntl d;  //!< Derivative controller
} pid_cntl;

/*! \brief Initialize Proportional-Integral-Derivative Controller
 *
 *  Assigns the proportional gain, kp, the
 *  integral gain, ki, and the derivative
 *  gain, kd, to a proportional-integral-derivative
 *  controller, cntl, and initializes the
 *  integral sum and last error values to zero.
 *
 *  \param cntl The proportional-integral-derivative controller
 *  \param kp The proportional gain
 *  \param ki The integral gain
 *  \param kd The derivative gain
 */
void pid_init(pid_cntl *cntl, unit_t kp, unit_t ki, unit_t kd);

/*! \brief Evaluate the Control Variable
 *
 *  Given a proportional-integral-derivative
 *  controller and target value, evaluate
 *  the control variable with respect to
 *  the current value. Dynamic clamping
 *  optional.
 *
 *  \param cntl The proportional-integral-derivative controller
 *  \param target_val The target value
 *  \param current_val The current value
 *  \param clmp Whether to clamp the control variable, non-zero if desired
 *  \return The control variable
 */
unit_t pid_eval(pid_cntl *cntl, unit_t target_val, unit_t current_val, int clmp);

#ifdef __cplusplus
}
#endif

#endif // PID_CNTL_H
