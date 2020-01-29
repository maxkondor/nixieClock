#include "RCC_Config.h"
#include "GPIO_Config.h"
#include "TIM_Config.h"
#include "I2C_Config.h"

#include "MenuManager.h"
	
int main (void)
{
	HAL_Init();
	
	RCC_Config();
	GPIO_Config();
	TIM_Config();
	I2C_Config();

	buttons control;
	
	while(1)
	{
		control = Buttons_GetKeyCode();
		Menu_Show(&control);
	}
}
