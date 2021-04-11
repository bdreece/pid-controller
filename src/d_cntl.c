/**
 * d_cntl.c
 *
 * @author Brian Reece
 */

#include "d_cntl.h"

void d_init(d_cntl *cntl, unit_t kd)
{
  cntl->kd = kd;
  cntl->last_err = (unit_t)0;
  return;
}

unit_t d_eval(d_cntl *cntl, unit_t target_val, unit_t current_val, int clmp)
{
  unit_t error, cv;

  error = target_val - current_val;
  error -= cntl->last_err;

  cv = cntl->kd * error;

  if (clmp)
    clamp(&cv);

  return cv;
}
