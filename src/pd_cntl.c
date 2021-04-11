/**
 * pd_cntl.c
 *
 * @author Brian Reece
 */

#ifndef PID_CONF_H
#include "pid_conf.h"
#endif

#include "pd_cntl.h"

void pd_init(pd_cntl *cntl, unit_t kp, unit_t kd)
{
  p_init(&cntl->p, kp);
  d_init(&cntl->d, kd);
  return;
}

unit_t pd_eval(pd_cntl *cntl, unit_t target_val, unit_t current_val, int clamp)
{
  unit_t cv;

  cv = p_eval(&cntl->p, target_val, current_val, 0);
  cv += d_eval(&cntl->d, target_val, current_val, 0);

  if (clamp)
    clamp(&cv);

  return cv;
}
