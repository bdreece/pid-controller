/**
 *  d_cntl.h
 *
 *  @author Brian Reece
 */

#ifndef D_CNTL_H
#define D_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pid_conf.h"

extern void clamp(unit_t *cv);

typedef struct {
  unit_t kd;
  unit_t last_err;
} d_cntl;

void d_init(d_cntl *cntl, unit_t kd);
unit_t d_eval(d_cntl *cntl, unit_t target_val, unit_t current_val, int clamp);

#ifdef __cplusplus
}
#endif

#endif // D_CNTL_H
