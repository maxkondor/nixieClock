#include "ButtonsInput.h"

/*========================================= Global Vars ============================================*/

bool 							ButtonIsPressed = false;
uint8_t 					NumOfLongClicks;

/*==================================================================================================*/

/*====================================== Function Prototypes =======================================*/

/*==================================================================================================*/

/*================================ Buttons_GetCurrentButtonState ===================================*/

static uint16_t Buttons_GetCurrentButtonState(void)
{
	static uint16_t retVal;
	static uint16_t buttVal;
	static uint16_t counter;
	
	if(Delay_GetTickVal() == true)
		counter++;
		
	
	if(HAL_GPIO_ReadPin(GPIO_BUTTONS_PORT, GPIO_BUTTON1_PIN) == GPIO_PIN_SET)
		buttVal |= GPIO_BUTTON1_PIN;
		
	if(HAL_GPIO_ReadPin(GPIO_BUTTONS_PORT, GPIO_BUTTON2_PIN) == GPIO_PIN_SET)
		buttVal |= GPIO_BUTTON2_PIN;
		
	if(HAL_GPIO_ReadPin(GPIO_BUTTONS_PORT, GPIO_BUTTON3_PIN) == GPIO_PIN_SET)
		buttVal |= GPIO_BUTTON3_PIN;
		
	if(counter == 5)
	{
		retVal = buttVal;
		counter = 0;
		buttVal = 0;
		
		if(retVal != 0)
		{
			ButtonIsPressed = true;
		}
				
		else ButtonIsPressed = false;
	}
	
	return retVal;
}
/*==================================================================================================*/

/*==================================== Buttons_GetCommand ==========================================*/

static buttonCommands Buttons_SetCommand(const uint16_t* buttonsVal)
{
	buttonCommands retVal = COMMAND_NOBUTTON;
	
	switch(*buttonsVal)
	{
		case GPIO_BUTTON1_PIN:
			retVal = COMMAND_INCREASING;
		break;
		
		case GPIO_BUTTON2_PIN:
			retVal = COMMAND_DECREASING;
		break;
		
		case GPIO_BUTTON3_PIN:
			retVal = COMMAND_MODE;
		break;
		
		default:
			retVal = COMMAND_NOBUTTON;
		break;
	}
		
	return retVal;
}

static void Buttons_GetInfo(buttonStateStruct* buttonInfo)
{
	uint16_t button = Buttons_GetCurrentButtonState();
	
	buttonInfo->ButtonCommand = Buttons_SetCommand(&button);
	buttonInfo->IsPressed = ButtonIsPressed;
	buttonInfo->PressingTime = Delay_GetPressedCounter();
}
/*==================================================================================================*/

/*====================================== Buttons_GetKeyCode ========================================*/

buttonCommands Buttons_GetCommand(void)
{
	buttonStateStruct buttonInfo;
	buttonCommands retVal = COMMAND_NOBUTTON;
	static buttonCommands oldCommand;
	static buttonCommands pressedButton;
	static bool isSticky;
	
	Buttons_GetInfo(&buttonInfo);
	
	if(buttonInfo.IsPressed == true && buttonInfo.ButtonCommand != COMMAND_NOBUTTON)
		pressedButton = buttonInfo.ButtonCommand;
	
	if(oldCommand != buttonInfo.ButtonCommand)
	{
		retVal = buttonInfo.ButtonCommand;
	}
	
	if(pressedButton == COMMAND_NOBUTTON)
		isSticky = false;
	
	oldCommand = buttonInfo.ButtonCommand;
	
	if(buttonInfo.PressingTime > BUTTONSINPUT_STICK_VALUE)
	{
		switch(pressedButton)
		{
			case COMMAND_MODE:
				if(isSticky == false)
				{
					NumOfLongClicks++;
					if(NumOfLongClicks ==3)
						NumOfLongClicks = 0;
					
					if(NumOfLongClicks == 1)
						retVal = COMMAND_EDITOR_MODE;
					
					if(NumOfLongClicks == 2)
						retVal = COMMAND_SAVE_CHANGES;
					isSticky = true;
				}
			break;
			
			case COMMAND_INCREASING:
				retVal = COMMAND_STICK_INCREASING;
			break;
			
			case COMMAND_DECREASING:
				retVal = COMMAND_STICK_DECREASING;
			break;
			
			default:
			break;
		}
		
		pressedButton = COMMAND_NOBUTTON;
	}
	
	return retVal;
}
/*==================================================================================================*/
