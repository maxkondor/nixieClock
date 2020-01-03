#ifndef TIM_CONFIG_H
#define TIM_CONFIG_H

#include "stm32f10x_tim.h"

#define NIXIE_TIM_PRESCALLER							4000
#define NIXIE_TIM_PERIOD									4

void TIM_Config(void);

#endif
