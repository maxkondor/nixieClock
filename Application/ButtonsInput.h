#ifndef BUTTONSINPUT_H
#define BUTTONSINPUT_H

#include "GPIO_Config.h"
#include "Delay.h"

#include <stdbool.h>

extern bool ButtonIsPressed;

typedef enum{
	
	BUTTON_NOBUTTON,
	BUTTON_CHANGE_UP,
	BUTTON_CHANGE_DOWN,
	BUTTON_MODE,
	BUTTON_MODE_SAVE_CHANGES,
	
}buttons;

buttons Buttons_GetCurrentButtonState(void);
buttons Buttons_ActiveButton(void);

#endif // BUTTONSINPUT_H
