#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

#include "stm32f1xx_hal.h"
#include "GPIO_Config.h"

typedef enum{
	GETVal,
	SETVal
}EXTI_ButtonsState;

void EXTI_Config(void);
uint16_t EXTI_ActiveButtons(EXTI_ButtonsState state);

#endif // EXTI_CONFIG_H
