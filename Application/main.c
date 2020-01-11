#include "RCC_Config.h"
#include "GPIO_Config.h"
#include "TIM_Config.h"
#include "I2C_Config.h"
#include "EXTI_Config.h"

#include "Nixie.h"



int main (void)
{
	HAL_Init();
	
	RCC_Config();
	GPIO_Config();
	TIM_Config();
	I2C_Config();
	EXTI_Config();
	
	while(1)
	{
		Nixie_ShowTime();
	}
}
