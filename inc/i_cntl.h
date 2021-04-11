/**
 *  i_cntl.h
 *
 *  @author Brian Reece
 */

#ifndef I_CNTL_H
#define I_CNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pid_conf.h"

extern void clamp(unit_t *cv);

typedef struct {
  unit_t ki;
  unit_t integral;
} i_cntl;

void i_init(i_cntl *cntl, unit_t ki);
unit_t i_eval(i_cntl *cntl, unit_t target_val, unit_t current_val, int clmp);

#ifdef __cplusplus
}
#endif

#endif // I_CNTL_H
