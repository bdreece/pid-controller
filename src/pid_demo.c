/**
 * pid_demo.c
 *
 * @author Brian Reece
 */

#include <stdio.h>
#include <stdlib.h>

#include "pid_cntl.h"

void poll(pid_cntl *cntl, unit_t target_val);

int main(int argc, char *argv[])
{
  unit_t target_val, kp, ki, kd;
  if (argc < 5)
  {
    printf("Usage: ./pid_demo target_val kp ki kd");
    return 1;
  }

  target_val = atof(argv[1]);
  kp = atof(argv[2]);
  ki = atof(argv[3]);
  kd = atof(argv[4]);

  pid_cntl cntl;

  pid_init(&cntl, kp, ki, kd);

  while(1)
    poll(&cntl, target_val);

  return 0;
}

void poll(pid_cntl *cntl, unit_t target_val)
{
  unit_t current_val, cv;

  printf("Enter current value: ");
  scanf("%lf\n", &current_val);

  cv = pid_eval(cntl, target_val, current_val, 1);

  printf("Control variable: %lf\n", cv);
  return;
}
