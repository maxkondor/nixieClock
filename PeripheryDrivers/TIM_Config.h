#ifndef TIM_CONFIG_H
#define TIM_CONFIG_H

#include "stm32f1xx_hal.h"

#define NIXIE_TIM_PRESCALLER							22999
#define NIXIE_TIM_PERIOD									6

#define NIXIE_DELAYTIM_PRESCALLER					359
#define NIXIE_DELAYTIM_PERIOD							0

extern TIM_HandleTypeDef 									TimerHandler;
extern TIM_HandleTypeDef									DelayTimerHandler;

void TIM_Config(void);

#endif
