/*! \file pd_cntl.h
 *  \brief Proportional-Derivative Controller
 */

#ifndef PD_CNTL_H
#define PD_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "p_cntl.h"
#include "d_cntl.h"

extern void clamp(unit_t *cv);

/*! \brief Proportional-Integral Controller Handle
 *
 *  Structure to handle configuration of a
 *  given instance of the proportional-integral
 *  controller.
 */
typedef struct {
  p_cntl p;  //!< Proportional controller
  d_cntl d;  //!< Derivative controller
} pd_cntl;

/*! \brief Initialize Proportional-Derivative Controller
 *
 *  Assigns the proportional gain, kp, and the
 *  derivative gain, kd, to the proportional-derivative
 *  controller, cntl, and initializes the last
 *  error value to zero
 *
 *  \param cntl The proportional-derivative controller
 *  \param kp The proportional gain
 *  \param kd The derivative gain
 */
void pd_init(pd_cntl *cntl, unit_t kp, unit_t kd);

/*! \brief Evaluate the Control Variable
 *
 *  Given a proportional-derivative controller
 *  and target value, evaluate the control
 *  variable with respect to the current
 *  value. Dynamic clamping optional.
 *
 *  \param cntl The proportional-derivative controller
 *  \param target_val The target value
 *  \param current_val The current value
 *  \param clmp Whether to clamp the control variable, non-zero if desired
 *  \return The control variable
 */
unit_t pd_eval(pd_cntl *cntl, unit_t target_val, unit_t current_val, int clmp);

#ifdef __cplusplus
}
#endif

#endif // PD_CNTL_H
