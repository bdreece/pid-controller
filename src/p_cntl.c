/**
 * p_cntl.c
 *
 * @author Brian Reece
 */

#ifndef PID_CONF_H
#include "pid_conf.h"
#endif

#include "p_cntl.h"

void p_init(p_cntl *cntl, unit_t kp)
{
  cntl->kp = kp;
  return;
}

unit_t p_eval(p_cntl *cntl, unit_t target_val, unit_t current_val, int clamp)
{
  unit_t error, cv;

  error = target_val - current_val;

  cv = cntl->kp * error;

  if (clamp)
    clamp(&cv);

  return cv;
}
