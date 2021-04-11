/**
 *  pid_cntl.h
 *
 *  @author Brian Reece
 */

#ifndef PID_CNTL_H
#define PID_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "p_cntl.h"
#include "i_cntl.h"
#include "d_ctnl.h"

extern void clamp(unit_t *cv);

typedef struct {
  p_cntl p;
  i_cntl i;
  d_cntl d;
} pi_cntl;

void pid_init(pid_cntl *cntl, unit_t kp, unit_t ki, unit_t kd);
unit_t pid_eval(pid_cntl *cntl, unit_t target_val, unit_t current_val, int clamp);

#ifdef __cplusplus
}
#endif

#endif // PID_CNTL_H
