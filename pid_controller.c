/**
 * pid_controller.c
 * 
 * @author Brian Reece 
 */

#include "pid_controller.h"

void __init(void *cntl, short type)
{

}

unit_t __update(void *cntl, short type, unit_t measurement)
{
    return 0;
}

void __set_k(void *cntl, short type, unit_t k)
{
    Controller controller;
    switch(type)
    {
    case 0:
        controller.p = (P_Controller *) cntl;
        controller.p->k = k;
        break;
    case 1:
        controller.i = (I_Controller *) cntl;
        controller.i->k = k;
        break;
    case 2:
        controller.pi = (PI_Controller *) cntl;
        controller.pi->k = k;
        break;
    case 3:
        controller.pd = (PD_Controller *) cntl;
        controller.pd->k = k;
        break;
    case 4:
        controller.pid = (PID_Controller *) cntl;
        controller.pid->k = k;
        break;
    }
}

void __set_setpoint(void *cntl, short type, unit_t setpoint)
{
    Controller controller;
    switch (type)
    {
    case 0:
        controller.p = (P_Controller *)cntl;
        controller.p->setpoint = setpoint;
        break;
    case 1:
        controller.i = (I_Controller *)cntl;
        controller.i->setpoint = setpoint;
        break;
    case 2:
        controller.pi = (PI_Controller *)cntl;
        controller.pi->setpoint = setpoint;
        break;
    case 3:
        controller.pd = (PD_Controller *)cntl;
        controller.pd->setpoint = setpoint;
        break;
    case 4:
        controller.pid = (PID_Controller *)cntl;
        controller.pid->setpoint = setpoint;
        break;
    }
}

void __set_tau_i(void *cntl, short type, unit_t tau_i)
{
    Controller controller;
    switch (type)
    {
    case 1:
        controller.i = (I_Controller *)cntl;
        controller.i->tau_i = tau_i;
        break;
    case 2:
        controller.pi = (PI_Controller *)cntl;
        controller.pi->tau_i = tau_i;
        break;
    case 3:
        controller.pd = (PD_Controller *)cntl;
        controller.pd->tau_i = tau_i;
        break;
    case 4:
        controller.pid = (PID_Controller *)cntl;
        controller.pid->tau_i = tau_i;
        break;
    }
}

unit_t __get_k(void *cntl, short type)
{
    Controller controller;
    unit_t k;

    switch(type)
    {
    case 0:
        controller.p = (P_Controller *) cntl;
        k = controller.p->k;
        break;
    case 1:
        controller.i = (I_Controller *)cntl;
        k = controller.i->k;
        break;
    case 2:
        controller.pi = (PI_Controller *)cntl;
        k = controller.pi->k;
        break;
    case 3:
        controller.pd = (PD_Controller *)cntl;
        k = controller.pd->k;
        break;
    case 4:
        controller.pid = (PID_Controller *)cntl;
        k = controller.pid->k;
        break;
    }

    return k;
}

unit_t __get_setpoint(void *cntl, short type)
{
    Controller controller;
    unit_t setpoint;

    switch(type)
    {
    case 0:
        controller.p = (P_Controller *) cntl;
        setpoint = controller.p->setpoint;
        break;
    case 1:
        controller.i = (I_Controller *)cntl;
        setpoint = controller.i->setpoint;
        break;
    case 2:
        controller.pi = (PI_Controller *)cntl;
        setpoint = controller.pi->setpoint;
        break;
    case 3:
        controller.pd = (PD_Controller *)cntl;
        setpoint = controller.pd->setpoint;
        break;
    case 4:
        controller.pid = (PID_Controller *)cntl;
        setpoint = controller.pid->setpoint;
        break;
    }

    return setpoint;
}

unit_t __get_theta(void *cntl, short type)
{
    Controller controller;
    unit_t theta;

    switch(type)
    {
    case 0:
        controller.p = (P_Controller *) cntl;
        theta = controller.p->theta;
        break;
    case 1:
        controller.i = (I_Controller *)cntl;
        theta = controller.i->theta;
        break;
    case 2:
        controller.pi = (PI_Controller *)cntl;
        theta = controller.pi->theta;
        break;
    case 3:
        controller.pd = (PD_Controller *)cntl;
        theta = controller.pd->theta;
        break;
    case 4:
        controller.pid = (PID_Controller *)cntl;
        theta = controller.pid->theta;
        break;
    }

    return theta;
}

unit_t __get_tau_i(void *cntl, short type)
{
    Controller controller;
    unit_t tau_i;

    switch (type)
    {
    case 1:
        controller.i = (I_Controller *)cntl;
        tau_i = controller.i->tau_i;
        break;
    case 2:
        controller.pi = (PI_Controller *)cntl;
        tau_i = controller.pi->tau_i;
        break;
    case 3:
        controller.pd = (PD_Controller *)cntl;
        tau_i = controller.pd->tau_i;
        break;
    case 4:
        controller.pid = (PID_Controller *)cntl;
        tau_i = controller.pid->tau_i;
        break;
    }

    return tau_i;
}

unit_t __get_reset(void *cntl, short type)
{
    Controller controller;
    unit_t reset;

    switch (type)
    {
    case 1:
        controller.i = (I_Controller *)cntl;
        reset = controller.i->reset;
        break;
    case 2:
        controller.pi = (PI_Controller *)cntl;
        reset = controller.pi->reset;
        break;
    case 4:
        controller.pid = (PID_Controller *)cntl;
        reset = controller.pid->reset;
        break;
    }

    return reset;
}

unit_t __get_d(void *cntl, short type)
{
    Controller controller;
    unit_t d;

    switch (type)
    {
    case 3:
        controller.pd = (PD_Controller *)cntl;
        d = controller.pd->d;
        break;
    case 4:
        controller.pid = (PID_Controller *)cntl;
        d = controller.pid->d;
        break;
    }

    return d;
}

unit_t __get_last_err(void *cntl, short type)
{
    Controller controller;
    unit_t last_err;

    switch (type)
    {
    case 3:
        controller.pd = (PD_Controller *)cntl;
        last_err = controller.pd->last_err;
        break;
    case 4:
        controller.pid = (PID_Controller *)cntl;
        last_err = controller.pid->last_err;
        break;
    }

    return last_err;
}