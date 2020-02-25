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
	I2C_ReInit();

	buttonCommands command;

	while(1)
	{
		command = Buttons_GetCommand();
		Menu_Show(&command);
		
//		switch(command)
//		{
//			case COMMAND_INCREASING:
//			break;
//			
//			case COMMAND_DECREASING:
//			break;
//			
//			case COMMAND_SAVE_CHANGES:
//			break;
//			
//			default:
//			break;	
//		}
	}
}
