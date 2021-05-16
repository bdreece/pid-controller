/*! \file pid_conf.h
 *  \brief Configuration Header
 */

#ifndef PID_CONF_H
#define PID_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

//! \brief Maximum value for dynamic clamping
#define LIM_MAX   255

//! \brief Minimum value for dynamic clamping
#define LIM_MIN   -255

//! \brief Datatype for control variable and gain values
typedef double unit_t;

/*! \brief Dynamic Clamping of Control Variable
 *
 *  Clamps the control variable based on macro
 *  constants above, namely LIM_MAX and LIM_MIN.
 *
 *  \param cv The control variable to clamp
 */
void clamp(unit_t *cv);

#ifdef __cplusplus
}
#endif

#endif // PID_CONF_H
