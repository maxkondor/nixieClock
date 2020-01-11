#include "EXTI_Config.h"

uint16_t ActiveButton = 0;

void EXTI_Config(void)
{
	  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 3, 2);
		HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_BUTTON1_PIN);
	HAL_GPIO_EXTI_IRQHandler(GPIO_BUTTON2_PIN);
	HAL_GPIO_EXTI_IRQHandler(GPIO_BUTTON3_PIN);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_BUTTON1_PIN)
		ActiveButton |= GPIO_BUTTON1_PIN;
	
	else if (GPIO_Pin == GPIO_BUTTON2_PIN)
		ActiveButton |= GPIO_BUTTON2_PIN;
	
	else ActiveButton |= GPIO_BUTTON3_PIN;
	
	EXTI_ActiveButtons(SETVal);
}

uint16_t EXTI_ActiveButtons(EXTI_ButtonsState state)
{
	uint16_t retData;
	
	retData	= ActiveButton;
	
	if(state == GETVal)	
		ActiveButton = 0;
	
	return retData;
}
