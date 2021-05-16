/*! \file i_cntl.h
 *  \brief Integral Controller
 */

#ifndef I_CNTL_H
#define I_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pid_conf.h"

extern void clamp(unit_t *cv);

/*! \brief Integral Controller Handle
 *
 *  Structure to handle configuration of a
 *  given instance of the integral controller.
 */
typedef struct {
  unit_t ki;        //!< Integral gain
  unit_t integral;  //!< Integral sum
} i_cntl;

/*! \brief Initialize Integral Controller
 *
 *  Assigns integral gain value, ki, to
 *  integral controller instance, cntl, and
 *  initializes integral sum value to 0.
 *
 *  \param cntl The integral controller
 *  \param ki The integral gain value
 */
void i_init(i_cntl *cntl, unit_t ki);

/*! \brief Evaluate the Control Variable
 *
 *  Given an integral controller and target,
 *  evaluate the control variable with respect
 *  to the current value. Dynamic clamping
 *  optional.
 *
 *  \param cntl The integral controller
 *  \param target_val The target value
 *  \param current_val The current value
 *  \param clmp Whether to clamp control variable, non-zero if desired
 *  \return The control variable
 */
unit_t i_eval(i_cntl *cntl, unit_t target_val, unit_t current_val, int clmp);

#ifdef __cplusplus
}
#endif

#endif // I_CNTL_H
