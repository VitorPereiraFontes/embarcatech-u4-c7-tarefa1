#ifndef _PWM_H
#define _PWM_H

#include "pico/stdlib.h"

void setup_pwm(uint pin,float pwm_clock_divisor, uint wrap, uint duty_cycle);

uint get_duty_cycle(uint wrap, float percentage);

#endif