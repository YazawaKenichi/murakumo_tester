#ifndef __DEFINES_H__
#define __DEFINES_H__

#include "stm32f4xx_hal.h"

#define EXTERN
#ifdef EXTERN
extern TIM_HandleTypeDef htim4;
void Error_Handler(void);
#endif //! EXTERN

#endif
