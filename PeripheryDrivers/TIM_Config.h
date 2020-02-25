#ifndef TIM_CONFIG_H
#define TIM_CONFIG_H

#include <stdbool.h>

#include "stm32f1xx_hal.h"
#include "GPIO_Config.h"

#define DataDisplay_TIM_PRESCALLER							22999
#define DataDisplay_TIM_PERIOD									6

#define DataDisplay_COUNTER_TIM_PRESCALLER			35999
#define DataDisplay_COUNTER_TIM_PERIOD					1

extern TIM_HandleTypeDef 									IndicationTimerHandler;
extern TIM_HandleTypeDef									CounterTimerHandler;

void TIM_Config(void);
bool TIM_DelayWithoutPause(uint16_t* delayTime);

#endif
