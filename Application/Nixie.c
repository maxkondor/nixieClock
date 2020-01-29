#include "Nixie.h"

/*======================================== Global Vars =============================================*/

bool FirstRead 							= true;
bool EditState 							= false;

ds3231_timeStr 							TimeStruct;
/*==================================================================================================*/

/*======================================== Global Enums ============================================*/

typedef enum{
	
	NIXIE_ARR_HOURS_TENS 			= 0,
	NIXIE_ARR_HOURS_UNITS,
	
	NIXIE_ARR_MINUTES_TENS,
	NIXIE_ARR_MINUTES_UNITS,
	
	NIXIE_ARR_SECONDS_TENS,
	NIXIE_ARR_SECONDS_UNITS,
	
}nixieDigitsTime;

typedef enum{
	
	NIXIE_PAIR_FIRST 					= 0,
	NIXIE_PAIR_SECOND 				= 2,
	NIXIE_PAIR_THIRD 					= 4,
	
}nixieDigitPairs;
/*==================================================================================================*/

/*====================================== Function Prototypes =======================================*/

void Nixie_DissasembleTime(uint8_t* lampArr, const ds3231_timeStr* timStruct);
void Nixie_SetNumberToArr(uint8_t* lampArr, const int8_t* number, const uint8_t* lampPair);
void Nixie_SaveTimeCnanges(ds3231_timeStr* timStruct, const uint8_t* lampArr);
void Nixie_CheckTimeValidation(int8_t* number, const uint8_t* lampPair);
void Nixie_BlinkLamps(uint8_t* lampArr, const uint8_t* lamp);

uint8_t Nixie_ChangeBlink(uint8_t* lampArr, buttons button);
uint8_t Nixie_GetNumberFromArr(const uint8_t* lampArr, const uint8_t* lampPair);
/*==================================================================================================*/

/*====================================== Nixie_DissasembleTime =====================================*/

void Nixie_DissasembleTime(uint8_t* lampArr, const ds3231_timeStr* timStruct)
{
	lampArr[NIXIE_ARR_HOURS_TENS] = timStruct->hours / 10;
	lampArr[NIXIE_ARR_HOURS_UNITS] = timStruct->hours % 10;
	
	lampArr[NIXIE_ARR_MINUTES_TENS] = timStruct->minutes / 10;
	lampArr[NIXIE_ARR_MINUTES_UNITS] = timStruct->minutes % 10;
	
	lampArr[NIXIE_ARR_SECONDS_TENS] = timStruct->seconds / 10;
	lampArr[NIXIE_ARR_SECONDS_UNITS] = timStruct->seconds % 10;
}
/*==================================================================================================*/

/*===================================== Nixie_GetNumberFromArr =====================================*/

uint8_t Nixie_GetNumberFromArr(const uint8_t* lampArr, const uint8_t* lampPair)
{
	uint8_t retNumber = lampArr[*lampPair] * 10;
	
	retNumber += lampArr[*lampPair + 1];
	
	return retNumber;
}
/*==================================================================================================*/

/*====================================== Nixie_SetNumberToArr ======================================*/

void Nixie_SetNumberToArr(uint8_t* lampArr, const int8_t* number, const uint8_t* lampPair)
{
	lampArr[*lampPair] = *number / 10;
	lampArr[*lampPair + 1] = *number % 10;
}
/*==================================================================================================*/

/*====================================== Nixie_SaveTimeCnanges =====================================*/

void Nixie_SaveTimeCnanges(ds3231_timeStr* timStruct, const uint8_t* lampArr)
{
	timStruct->hours = lampArr[NIXIE_ARR_HOURS_TENS] * 10 + lampArr[NIXIE_ARR_HOURS_UNITS];
	timStruct->minutes = lampArr[NIXIE_ARR_MINUTES_TENS] * 10 + lampArr[NIXIE_ARR_MINUTES_UNITS];
	timStruct->seconds = lampArr[NIXIE_ARR_SECONDS_TENS] * 10 + lampArr[NIXIE_ARR_SECONDS_UNITS];
}
/*==================================================================================================*/

/*==================================== Nixie_CheckTimeValidation ===================================*/

void Nixie_CheckTimeValidation(int8_t* number, const uint8_t* lampPair)
{
	switch(*lampPair)
	{
		case NIXIE_PAIR_FIRST:
			if(*number < 0)
				*number = 23;
			
			if(*number > 23)
				*number = 0;
			break;
			
		case NIXIE_PAIR_SECOND:
			if(*number < 0)
				*number = 59;
			
			if(*number > 59)
				*number = 0;
		
		case NIXIE_PAIR_THIRD:
			if(*number < 0)
				*number = 59;
			
			if(*number > 59)
				*number = 0;
			break;		
	}
}
/*==================================================================================================*/

/*========================================= Nixie_BlinkLamps =======================================*/

void Nixie_BlinkLamps(uint8_t* lampArr, const uint8_t* lamp)
{
	static uint8_t dataBuffer[2];
	static uint8_t oldData;
	
	dataBuffer[0] = lampArr[*lamp];
	dataBuffer[1] = lampArr[*lamp + 1];
	
	if(Delay_NoPause(NIXIE_BLINK_TIME) == true)
	{
		lampArr[*lamp] = DYNAMIC_LAMP_UNACTIVE;
		lampArr[*lamp + 1] = DYNAMIC_LAMP_UNACTIVE;
	}
	
	else
	{
		lampArr[*lamp] = dataBuffer[0];
		lampArr[*lamp + 1] = dataBuffer[1];
	}
	
	if(oldData != *lamp)
		Delay_ResetCounter();
	
	oldData = *lamp;
}
/*==================================================================================================*/

/*======================================== Nixie_ChangeBlink =======================================*/

uint8_t Nixie_ChangeBlink(uint8_t* lampArr, buttons button)
{
	static uint8_t lampsCounter;
	
	if(button == BUTTON_MODE)
	{
		lampsCounter +=2;
		
		if(lampsCounter > 5)
			lampsCounter = 0;
	}
	
	if(EditState == false)
		Nixie_BlinkLamps(lampArr, &lampsCounter);
	
	return lampsCounter;
}
/*==================================================================================================*/

/*========================================= Nixie_ShowTime =========================================*/

nixieActions Nixie_ShowTime(dynamicAnimations animType)
{
	nixieActions action = NIXIE_ACTION_IS_SHOWING_TIME;
	
	uint8_t lampsArr[DYNAMIC_NUM_OF_LAMPS];
	ds3231_timeStr timStruct;
	
	DS3231_ReadTime(&timStruct);
	Nixie_DissasembleTime(lampsArr, &timStruct);
	Dynamic_ParseArr(lampsArr, animType);
	
	return action;
}
/*==================================================================================================*/

/*========================================= Nixie_EditTime =========================================*/
nixieActions Nixie_EditTime(buttons* control)
{
	nixieActions action = NIXIE_ACTION_IS_EDITING_TIME;
	uint8_t lampsArr[DYNAMIC_NUM_OF_LAMPS];
	int8_t lampsPairNumber;
	uint8_t lampsCounter;

	if(FirstRead == true)
 	{
		DS3231_ReadTime(&TimeStruct);
		*control = BUTTON_NOBUTTON;
		FirstRead = false;
		EditState = false;
	}
	
	Nixie_DissasembleTime(lampsArr, &TimeStruct);
	lampsCounter = Nixie_ChangeBlink(lampsArr, *control);
	
	if(*control == BUTTON_CHANGE_UP || *control == BUTTON_CHANGE_DOWN)
	{
		Nixie_DissasembleTime(lampsArr, &TimeStruct);
		lampsPairNumber = Nixie_GetNumberFromArr(lampsArr, &lampsCounter);
		EditState = true;
		
		if(*control == BUTTON_CHANGE_UP)
			lampsPairNumber++;
		
		else if(*control == BUTTON_CHANGE_DOWN)
			lampsPairNumber--;
		
		Nixie_CheckTimeValidation(&lampsPairNumber, &lampsCounter);
		Nixie_SetNumberToArr(lampsArr, &lampsPairNumber, &lampsCounter);
		Nixie_SaveTimeCnanges(&TimeStruct, lampsArr);
	}
	
	if(*control == BUTTON_MODE)
		EditState = false;
	
	if(*control == BUTTON_MODE_SAVE_CHANGES)
	{
		DS3231_WriteTime(&TimeStruct);
		FirstRead = true;
		action = NIXIE_ACTION_END_OF_TIME_EDIT;
	}
	
	Dynamic_ParseArr(lampsArr, DYNAMIC_ANIMATION_NONE);
	
	return action;
}
/*==================================================================================================*/
