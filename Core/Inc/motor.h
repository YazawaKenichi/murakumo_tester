#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "defines.h"
#include "stm32f4xx_hal.h"

#define PWMMAX 1000

void motor_init();
void motor_start();
void motor_stop();
void motor_set_enable(uint8_t motor_enable);
uint8_t motor_read_enable();
void motor_set(float, float);

#endif
