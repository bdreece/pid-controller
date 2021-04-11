/**
 *  pi_cntl.h
 *
 *  @author Brian Reece
 */

#ifndef PI_CNTL_H
#define PI_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "p_cntl.h"
#include "i_cntl.h"

extern void clamp(unit_t *cv);

typedef struct {
  p_cntl p;
  i_cntl i;
} pi_cntl;

void pi_init(pi_cntl *cntl, unit_t kp, unit_t ki);
unit_t pi_eval(pi_cntl *cntl, unit_t target_val, unit_t current_val, int clamp);

#ifdef __cplusplus
}
#endif

#endif // PI_CNTL_H
