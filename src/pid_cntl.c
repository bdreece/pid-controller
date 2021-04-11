/**
 * pid_cntl.c
 *
 * @author Brian Reece
 */

#ifndef PID_CONF_H
#include "pid_conf.h"
#endif

#include "pid_cntl.h"

void pid_init(pid_cntl *cntl, unit_t kp, unit_t ki, unit_t kd)
{
  p_init(&cntl->p, kp);
  i_init(&cntl->i, ki);
  d_init(&cntl->d, kd);
}

unit_t pid_eval(pid_cntl *cntl, unit_t target_val, unit_t current_val, int clamp)
{
  unit_t cv;

  cv = p_eval(&cntl->p, target_val, current_val, 0);
  cv += i_eval(&cntl->i, target_val, current_val, 0);
  cv += d_eval(&cntl->d, target_val, current_val, 0);

  if (clamp)
    clamp(&cv);

  return cv;
}
