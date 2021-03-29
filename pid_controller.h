/**
 * pid_controller.h
 * 
 * @author Brian Reece 
 */
#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#define P_CNTL   0
#define I_CNTL   1
#define PI_CNTL  2
#define PD_CNTL  3
#define PID_CNTL 4

typedef double unit_t;

// Proportional Controller
typedef struct {
    unit_t k;
    unit_t setpoint;
    unit_t theta;
} P_Controller;

// Proportional-Integral Controller
typedef struct {
    unit_t k;
    unit_t setpoint;
    unit_t theta;
    unit_t tau_i;
    unit_t reset;
} PI_Controller;

// Integral Controller
typedef PI_Controller I_Controller;

// Proportional-Derivative Controller
typedef struct {
    unit_t k;
    unit_t setpoint;
    unit_t theta;
    unit_t tau_i;
    unit_t d;
    unit_t last_err;
} PD_Controller;

// Proportional-Integral-Derivative Controller
typedef struct {
    unit_t k;
    unit_t setpoint;
    unit_t theta;
    unit_t tau_i;
    unit_t reset;
    unit_t d;
    unit_t last_err;
} PID_Controller;

typedef union {
    P_Controller *p;
    I_Controller *i;
    PI_Controller *pi;
    PD_Controller *pd;
    PID_Controller *pid;
} Controller;

void __init(void *cntl, short type);
unit_t __update(void *cntl, short type, unit_t measurement);

void __set_k(void *cntl, short type, unit_t k);
void __set_setpoint(void *cntl, short type, unit_t setpoint);
void __set_tau_i(void *cntl, short type, unit_t tau_i);

unit_t __get_k(void *cntl, short type);
unit_t __get_setpoint(void *cntl, short type);
unit_t __get_theta(void *cntl, short type);
unit_t __get_tau_i(void *cntl, short type);
unit_t __get_reset(void *cntl, short type);
unit_t __get_d(void *cntl, short type);
unit_t __get_last_err(void *cntl, short type);

#define P_init(cntl) __init((void *)cntl, P_CNTL)
#define I_init(cntl) __init((void *)cntl, I_CNTL)
#define PI_init(cntl) __init((void *)cntl, PI_CNTL)
#define PD_init(cntl) __init((void *)cntl, PD_CNTL)
#define PID_init(cntl) __init((void *)cntl, PID_CNTL)

#define P_update(cntl, meas) __update((void *)cntl, P_CNTL, meas)
#define I_update(cntl, meas) __update((void *)cntl, I_CNTL, meas)
#define PI_update(cntl, meas) __update((void *)cntl, PI_CNTL, meas)
#define PD_update(cntl, meas) __update((void *)cntl, PD_CNTL, meas)
#define PID_update(cntl, meas) __update((void *)cntl, PID_CNTL, meas)

#define P_set_k(cntl, k) __set_k((void *)cntl, P_CNTL, k)
#define I_set_k(cntl, k) __set_k((void *)cntl, I_CNTL, k)
#define PI_set_k(cntl, k) __set_k((void *)cntl, PI_CNTL, k)
#define PD_set_k(cntl, k) __set_k((void *)cntl, PD_CNTL, k)
#define PID_set_k(cntl, k) __set_k((void *)cntl, PID_CNTL, k)

#define P_set_setpoint(cntl, setpoint) __set_setpoint((void *)cntl, P_CNTL, setpoint)
#define I_set_setpoint(cntl, setpoint) __set_setpoint((void *)cntl, I_CNTL, setpoint)
#define PI_set_setpoint(cntl, setpoint) __set_setpoint((void *)cntl, PI_CNTL, setpoint)
#define PD_set_setpoint(cntl, setpoint) __set_setpoint((void *)cntl, PD_CNTL, setpoint)
#define PID_set_setpoint(cntl, setpoint) __set_setpoint((void *)cntl, PID_CNTL, setpoint)

#define I_set_tau_i(cntl, tau_i) __set_tau_i((void *)cntl, I_CNTL, tau_i)
#define PI_set_tau_i(cntl, tau_i) __set_tau_i((void *)cntl, PI_CNTL, tau_i)
#define PD_set_tau_i(cntl, tau_i) __set_tau_i((void *)cntl, PD_CNTL, tau_i)
#define PID_set_tau_i(cntl, tau_i) __set_tau_i((void *)cntl, PID_CNTL, tau_i)

#define P_get_k(cntl) __get_k((void *)cntl, P_CNTL)
#define I_get_k(cntl) __get_k((void *)cntl, I_CNTL)
#define PI_get_k(cntl) __get_k((void *)cntl, PI_CNTL)
#define PD_get_k(cntl) __get_k((void *)cntl, PD_CNTL)
#define PID_get_k(cntl) __get_k((void *)cntl, PID_CNTL)

#define P_get_setpoint(cntl) __get_setpoint((void *)cntl, P_CNTL)
#define I_get_setpoint(cntl) __get_setpoint((void *)cntl, I_CNTL)
#define PI_get_setpoint(cntl) __get_setpoint((void *)cntl, PI_CNTL)
#define PD_get_setpoint(cntl) __get_setpoint((void *)cntl, PD_CNTL)
#define PID_get_setpoint(cntl) __get_setpoint((void *)cntl, PID_CNTL)

#define P_get_theta(cntl) __get_theta((void *)cntl, P_CNTL)
#define I_get_theta(cntl) __get_theta((void *)cntl, I_CNTL)
#define PI_get_theta(cntl) __get_theta((void *)cntl, PI_CNTL)
#define PD_get_theta(cntl) __get_theta((void *)cntl, PD_CNTL)
#define PID_get_theta(cntl) __get_theta((void *)cntl, PID_CNTL)

#define I_get_tau_i(cntl) __get_tau_i((void *)cntl, I_CNTL)
#define PI_get_tau_i(cntl) __get_tau_i((void *)cntl, PI_CNTL)
#define PD_get_tau_i(cntl) __get_tau_i((void *)cntl, PD_CNTL)
#define PID_get_tau_i(cntl) __get_tau_i((void *)cntl, PID_CNTL)

#define I_get_reset(cntl) __get_reset((void *)cntl, I_CNTL)
#define PI_get_reset(cntl) __get_reset((void *)cntl, PI_CNTL)
#define PID_get_reset(cntl) __get_reset((void *)cntl, PID_CNTL)

#define PD_get_d(cntl) __get_d((void *)cntl, PD_CNTL)
#define PID_get_d(cntl) __get_d((void *)cntl, PID_CNTL)

#define PD_get_last_err(cntl) __get_last_err((void *)cntl, PD_CNTL)
#define PID_get_last_err(cntl) __get_last_err((void *)cntl, PID_CNTL)

#endif