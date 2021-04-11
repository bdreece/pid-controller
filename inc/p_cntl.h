/**
 *  p_cntl.h
 *
 *  @author Brian Reece
 */

#ifndef P_CNTL_H
#define P_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pid_conf.h"

extern void clamp(unit_t *cv);

typedef struct {
  unit_t kp;
} p_cntl;

void p_init(p_cntl *cntl, unit_t kp);
unit_t p_eval(p_cntl *cntl, unit_t target_val, unit_t current_val, int clmp);

#ifdef __cplusplus
}
#endif

#endif // P_CNTL_H
