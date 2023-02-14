#include "motor.h"

uint8_t motor_enable;

void motor_init()
{
	motor_set_enable(0);
}

void motor_start()
{
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	motor_set_enable(1);
}

void motor_stop()
{
	motor_set_enable(0);
	HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_2);
	HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
}

void motor_set_enable(uint8_t enable_)
{
	motor_enable = enable_ ? 1 : 0;
}

uint8_t motor_read_enable()
{
	return motor_enable;
}

void motor_set(float motor_left, float motor_right)
{
	if(motor_left < 0)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
		motor_left = motor_left * -1;
	}
	else
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
	}

	if(motor_right < 0)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
		motor_left = motor_left * -1;
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	}

	motor_left = motor_left > PWMMAX ? PWMMAX : motor_left;
	motor_right = motor_right > PWMMAX ? PWMMAX : motor_right;

	if(!motor_enable)
	{
		motor_left = 0;
		motor_right = 0;
	}

	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, motor_left);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, motor_right);
}


