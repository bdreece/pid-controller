/**
 *  pid_conf.h
 *
 *  @author Brian Reece
 */

#ifndef PID_CONF_H
#define PID_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/*  USER-DEFINED CONSTANTS  */
#define LIM_MAX   255
#define LIM_MIN   -255

/*  USER-DEFINED TYPES  */
typedef double unit_t;

/*  UTILITY FUNCTIONS */
void clamp(unit_t *cv);

#ifdef __cplusplus
}
#endif

#endif // PID_CONF_H
