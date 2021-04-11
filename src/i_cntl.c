/**
 * i_cntl.c
 *
 * @author Brian Reece
 */

#ifndef PID_CONF_H
#include "pid_conf.h"
#endif

#include "i_cntl.h"

void i_init(i_cntl *cntl, unit_t ki)
{
  cntl->ki = ki;
  cntl->integral = (unit_t)0;
  return;
}

unit_t i_eval(i_cntl *cntl, unit_t target_val, unit_t current_val, int clamp)
{
  unit_t error, cv;

  error = target_val - current_val;

  cntl->integral += error;

  cv = cntl->ki * cntl->integral;

  if (clamp)
    clamp(&cv);

  return cv;
}
