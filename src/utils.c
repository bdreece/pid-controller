//! \file utils.c

#include "pid_conf.h"

void clamp(unit_t *cv)
{
  *cv = (*cv > LIM_MAX) ? LIM_MAX : *cv;
  *cv = (*cv < LIM_MIN) ? LIM_MIN : *cv;
}
