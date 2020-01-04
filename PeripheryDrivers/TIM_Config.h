#ifndef TIM_CONFIG_H
#define TIM_CONFIG_H

#include "stm32f1xx_hal.h"

extern TIM_HandleTypeDef 									TimerHandler;

#define NIXIE_TIM_PRESCALLER							22999
#define NIXIE_TIM_PERIOD									6

void TIM_Config(void);

#endif
