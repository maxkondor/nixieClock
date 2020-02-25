#ifndef DATAEDITOR_H
#define	DATAEDITOR_H

#include "TIM_Config.h"
#include "DS3231.h"
#include "Delay.h"
#include "DynamicIndication.h"
#include "ButtonsInput.h"

/*====================================== Global Defines ============================================*/

#define NIXIE_BLINK_TIME 						500
#define NIXIE_UPDATE_VAL						50
/*==================================================================================================*/

/*======================================== Global Enums ============================================*/

typedef enum
{
	NIXIE_ACTION_IS_SHOWING_TIME,
	NIXIE_ACTION_IS_EDITING_TIME,
	NIXIE_ACTION_END_OF_TIME_EDIT,
	NIXIE_ACTION_IS_SHOWING_DATE,
	NIXIE_ACTION_IS_EDITING_DATE,
	NIXIE_ACTION_END_OF_DATE_EDIT,	
}nixieActions;
/*==================================================================================================*/

void DataDisplay_DissasembleTime(uint8_t* lampArr, const ds3231_timeStruct* timeStruct);
void DataDisplay_DissasembleDate(uint8_t* lampArr, const ds3231_dateStruct* dateStruct);
nixieActions DataDisplay_EditTime(buttonCommands command);
nixieActions DataDisplay_EditDate(buttonCommands command);



#endif // DATAEDITOR_H
