/**
 *  pd_cntl.h
 *
 *  @author Brian Reece
 */

#ifndef PD_CNTL_H
#define PD_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "p_cntl.h"
#include "d_cntl.h"

extern void clamp(unit_t *cv);

typedef struct {
  p_cntl p;
  d_cntl d;
} pd_cntl;

void pd_init(pd_cntl *cntl, unit_t kp, unit_t kd);
unit_t pd_eval(pd_cntl *cntl, unit_t target_val, unit_t current_val, int clmp);

#ifdef __cplusplus
}
#endif

#endif // PD_CNTL_H
