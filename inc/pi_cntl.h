/*! \file pi_cntl.h
 *  \brief Proportional-Integral Controller
 */

#ifndef PI_CNTL_H
#define PI_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "p_cntl.h"
#include "i_cntl.h"

extern void clamp(unit_t *cv);

/*! \brief Proportional-Integral Controller Handle
 *
 *  Structure to handle configuration of a
 *  given instance of the proportional-integral
 *  controller.
 */
typedef struct {
  p_cntl p;  //!< Proportional Controller
  i_cntl i;  //!< Integral Controller
} pi_cntl;

/*! \brief Initialize Proportional-Integral Controller
 *
 *  Assigns the proportional gain, kp, and the
 *  integral gain, ki, to the proportional-integral
 *  controller, cntl, and initializes integral
 *  sum to zero.
 *
 *  \param cntl The proportional-integral controller
 *  \param kp The proportional gain
 *  \param ki The integral gain
 */
void pi_init(pi_cntl *cntl, unit_t kp, unit_t ki);

/*! \brief Evaluate the Control Variable
 *
 *  Given a proportional-integral controller
 *  and target value, evaluate the control
 *  variable with respect to the current value.
 *  Dynamic clamping optional.
 *
 *  \param cntl The proportional-integral controller
 *  \param target_val The target value
 *  \param current_val The current value
 *  \param clmp Whether to clamp the control variable, non-zero if desired
 *  \return The control variable
 */
unit_t pi_eval(pi_cntl *cntl, unit_t target_val, unit_t current_val, int clmp);

#ifdef __cplusplus
}
#endif

#endif // PI_CNTL_H
