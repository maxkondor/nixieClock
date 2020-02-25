#ifndef BUTTONSINPUT_H
#define BUTTONSINPUT_H

#include "GPIO_Config.h"
#include "Delay.h"

#include <stdbool.h>

/*======================================= Global Defines ===========================================*/

#define BUTTONSINPUT_STICK_VALUE		1000
/*==================================================================================================*/

/*========================================= Global Vars ============================================*/

extern bool ButtonIsPressed;
/*==================================================================================================*/


/*======================================== Global Enums ============================================*/

typedef enum
{
	COMMAND_NOBUTTON									= 0x00,
	COMMAND_INCREASING,  										
	COMMAND_DECREASING,
	COMMAND_MODE,
	COMMAND_SAVE_CHANGES,
	COMMAND_EDITOR_MODE,
	COMMAND_STICK_INCREASING,
	COMMAND_STICK_DECREASING,
}buttonCommands;


typedef struct
{
	buttonCommands 										ButtonCommand;
	bool					 										IsPressed;
	uint16_t 			 										PressingTime;
}buttonStateStruct;
/*==================================================================================================*/

/*====================================== Function Prototypes =======================================*/

buttonCommands Buttons_GetCommand(void);
/*==================================================================================================*/

#endif // BUTTONSINPUT_H
