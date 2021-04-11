/**
 * pi_cntl.c
 *
 * @author Brian Reece
 */

#include "pi_cntl.h"

void pi_init(pi_cntl *cntl, unit_t kp, unit_t ki)
{
  p_init(&cntl->p, kp);
  i_init(&cntl->i, ki);
  return;
}

unit_t pi_eval(pi_cntl *cntl, unit_t target_val, unit_t current_val, int clmp)
{
  unit_t cv;

  cv = p_eval(&cntl->p, target_val, current_val, 0);
  cv += i_eval(&cntl->i, target_val, current_val, 0);

  if (clmp)
    clamp(&cv);

  return cv;
}
