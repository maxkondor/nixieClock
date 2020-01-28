#include "ButtonsInput.h"

bool ButtonIsPressed = false;

buttons Buttons_GetCurrentButtonState(void)
{
	buttons retVal = BUTTON_NOBUTTON;
	static buttons buttVal;
	static uint16_t counter;
	
	if(Delay_GetTickVal() == true)
		counter++;
	
	if(HAL_GPIO_ReadPin(GPIO_BUTTONS_PORT, GPIO_BUTTON1_PIN) == GPIO_PIN_SET)
			buttVal = BUTTON_CHANGE_UP;
		
	if(HAL_GPIO_ReadPin(GPIO_BUTTONS_PORT, GPIO_BUTTON2_PIN) == GPIO_PIN_SET)
		buttVal = BUTTON_CHANGE_DOWN;
		
	if(HAL_GPIO_ReadPin(GPIO_BUTTONS_PORT, GPIO_BUTTON3_PIN) == GPIO_PIN_SET)
		buttVal = BUTTON_MODE;	
	
	if((HAL_GPIO_ReadPin(GPIO_BUTTONS_PORT, GPIO_BUTTON1_PIN) == GPIO_PIN_SET) && (HAL_GPIO_ReadPin(GPIO_BUTTONS_PORT, GPIO_BUTTON3_PIN) == GPIO_PIN_SET))
		buttVal = BUTTON_MODE_SAVE_CHANGES;

	if(counter > 40)
	{
		retVal = buttVal;
		counter = 0;
		buttVal = BUTTON_NOBUTTON;
		
		if(retVal != BUTTON_NOBUTTON)
		{
			ButtonIsPressed = true;
		}
		
		
		else ButtonIsPressed = false;
	}
	
	return retVal;
}

buttons Buttons_ActiveButton(void)
{
	static bool oldButtonState;
	buttons currentButton;
	buttons retData = BUTTON_NOBUTTON;
	
	currentButton = Buttons_GetCurrentButtonState();
	
	if(oldButtonState != ButtonIsPressed && ButtonIsPressed == true)
	{
		retData = currentButton;
	}
	
	oldButtonState = ButtonIsPressed;
	
	return retData;
}
