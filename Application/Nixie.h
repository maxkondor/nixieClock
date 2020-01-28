#ifndef NIXIE_H
#define NIXIE_H

#include "TIM_Config.h"
#include "DS3231.h"
#include "Delay.h"
#include "DynamicIndication.h"
#include "ButtonsInput.h"

#define NIXIE_BLINK_TIME 						500

typedef enum{
	
	NIXIE_ACTION_IS_SHOWING_TIME,
	NIXIE_ACTION_IS_EDITING_TIME,
	NIXIE_ACTION_END_OF_TIME_EDIT,
	
	NIXIE_ACTION_IS_SHOWING_DATE,
	NIXIE_ACTION_IS_EDITING_DATE,
	NIXIE_ACTION_END_OF_DATE_EDIT,
	
}nixieActions;

nixieActions Nixie_ShowTime(dynamicAnimations animType);
nixieActions Nixie_EditTime(buttons* control);

#endif // NIXIE_H
