#include "DataEditor.h"

/*=========================================== Global Vars ================================================*/

bool 								FirstRead = true;
bool 								EditState = false;
extern uint8_t 			NumOfLongClicks;
ds3231_timeStruct 	TimeStruct;
ds3231_dateStruct		DateStruct;


/*========================================================================================================*/

/*=========================================== Global Enums ===============================================*/

typedef enum
{
	NIXIE_ARR_FIRST_LAMP 			= 0,
	NIXIE_ARR_SECOND_LAMP,
	
	NIXIE_ARR_THIRD_LAMP,
	NIXIE_ARR_FOURTH_LAMP,
	
	NIXIE_ARR_FIFTH_LAMP,
	NIXIE_ARR_SIXTH_LAMP,
}nixieDigitsTime;

typedef enum
{
	NIXIE_PAIR_FIRST 					= 0,
	NIXIE_PAIR_SECOND 				= 2,
	NIXIE_PAIR_THIRD 					= 4,
}nixieDigitPairs;

typedef enum
{
	NIXIE_MONTH_JANUARY				= 0,
	NIXIE_MONTH_FEBFUARY,
	NIXIE_MONTH_MARCH,
	NIXIE_MONTH_APRIL,
	NIXIE_MONTH_MAY,
	NIXIE_MONTH_JUNE,
	NIXIE_MONTH_JULY,
	NIXIE_MONTH_AUGUST,
	NIXIE_MONTH_SEPTEMBER,
	NIXIE_MONTH_OCTOBER,
	NIXIE_MONTH_NOVEMBER,
	NIXIE_MONTH_DECEMBER,
}nixieMonthes;
/*========================================================================================================*/

uint8_t MonthesArray[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

/*========================================= Function Prototypes ==========================================*/

static void DataDisplay_SetNumberToArr(uint8_t* lampArr, int8_t* number, const uint8_t* lampPair);
static void DataDisplay_SaveTimeCnanges(ds3231_timeStruct* timeStruct, const uint8_t* lampArr);
static void DataDisplay_SaveDateCnanges(ds3231_dateStruct* dateStruct, const uint8_t* lampArr);
static void DataDisplay_CheckTimeValidation(int8_t* number, const uint8_t* lampPair);
static void DataDisplay_BlinkLamps(uint8_t* lampArr, const uint8_t* lamp);

static uint8_t DataDisplay_ChangeBlink(uint8_t* lampArr, const buttonCommands* command);
static uint8_t DataDisplay_GetNumberFromArr(const uint8_t* lampArr, const uint8_t* lampPair);
/*========================================================================================================*/

/*====================================== DataDisplay_DissasembleTime =====================================*/

void DataDisplay_DissasembleTime(uint8_t* lampArr, const ds3231_timeStruct* timeStruct)
{
	lampArr[NIXIE_ARR_FIRST_LAMP] = timeStruct->hours / 10;
	lampArr[NIXIE_ARR_SECOND_LAMP] = timeStruct->hours % 10;
	
	lampArr[NIXIE_ARR_THIRD_LAMP] = timeStruct->minutes / 10;
	lampArr[NIXIE_ARR_FOURTH_LAMP] = timeStruct->minutes % 10;
	
	lampArr[NIXIE_ARR_FIFTH_LAMP] = timeStruct->seconds / 10;
	lampArr[NIXIE_ARR_SIXTH_LAMP] = timeStruct->seconds % 10;
}
/*========================================================================================================*/

/*====================================== DataDisplay_DissasembleDate =====================================*/

void DataDisplay_DissasembleDate(uint8_t* lampArr, const ds3231_dateStruct* dateStruct)
{
	lampArr[NIXIE_ARR_FIRST_LAMP] = dateStruct->date / 10;
	lampArr[NIXIE_ARR_SECOND_LAMP] = dateStruct->date % 10;
	
	lampArr[NIXIE_ARR_THIRD_LAMP] = dateStruct->month / 10;
	lampArr[NIXIE_ARR_FOURTH_LAMP] = dateStruct->month % 10;
	
	lampArr[NIXIE_ARR_FIFTH_LAMP] = dateStruct->year / 10;
	lampArr[NIXIE_ARR_SIXTH_LAMP] = dateStruct->year % 10;
}
/*========================================================================================================*/

/*===================================== DataDisplay_GetNumberFromArr =====================================*/

static uint8_t DataDisplay_GetNumberFromArr(const uint8_t* lampArr, const uint8_t* lampPair)
{
	uint8_t retNumber = lampArr[*lampPair] * 10;
	
	retNumber += lampArr[*lampPair + 1];
	
	return retNumber;
}
/*========================================================================================================*/

/*====================================== DataDisplay_SetNumberToArr ======================================*/

static void DataDisplay_SetNumberToArr(uint8_t* lampArr, int8_t* number, const uint8_t* lampPair)
{
	lampArr[*lampPair] = *number / 10;
	lampArr[*lampPair + 1] = *number % 10;
}
/*========================================================================================================*/

/*====================================== DataDisplay_SaveTimeCnanges =====================================*/

static void DataDisplay_SaveTimeCnanges(ds3231_timeStruct* timeStruct, const uint8_t* lampArr)
{
	timeStruct->hours = lampArr[NIXIE_ARR_FIRST_LAMP] * 10 + lampArr[NIXIE_ARR_SECOND_LAMP];
	timeStruct->minutes = lampArr[NIXIE_ARR_THIRD_LAMP] * 10 + lampArr[NIXIE_ARR_FOURTH_LAMP];
	timeStruct->seconds = lampArr[NIXIE_ARR_FIFTH_LAMP] * 10 + lampArr[NIXIE_ARR_SIXTH_LAMP];
}
/*========================================================================================================*/

/*====================================== DataDisplay_SaveDateCnanges =====================================*/

static void DataDisplay_SaveDateCnanges(ds3231_dateStruct* dateStruct, const uint8_t* lampArr)
{
	dateStruct->date = lampArr[NIXIE_ARR_FIRST_LAMP] * 10 + lampArr[NIXIE_ARR_SECOND_LAMP];
	dateStruct->month = lampArr[NIXIE_ARR_THIRD_LAMP] * 10 + lampArr[NIXIE_ARR_FOURTH_LAMP];
	dateStruct->year = lampArr[NIXIE_ARR_FIFTH_LAMP] * 10 + lampArr[NIXIE_ARR_SIXTH_LAMP];
}
/*========================================================================================================*/

/*==================================== DataDisplay_CheckTimeValidation ===================================*/

static void DataDisplay_CheckTimeValidation(int8_t* number, const uint8_t* lampPair)
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
		break;
			
		case NIXIE_PAIR_THIRD:
			if(*number < 0)
				*number = 59;
			
			if(*number > 59)
				*number = 0;
		break;		
	}
}
/*========================================================================================================*/

/*==================================== DataDisplay_CheckDateValidation ===================================*/

static void DataDisplay_CheckDateValidation(uint8_t* lampArr, int8_t* number, const uint8_t* lampPair)
{
	const uint8_t daysVal = 0;
	const uint8_t monthVal = 2;
	const uint8_t yearsVal = 4;
	bool isGreatYear = false;
	uint8_t monthMaxVal;
	int8_t intVal;
	
	switch(*lampPair)
	{
		case NIXIE_PAIR_FIRST:
			monthMaxVal = MonthesArray[DataDisplay_GetNumberFromArr(lampArr, &monthVal) - 1];
		
			if(DataDisplay_GetNumberFromArr(lampArr, &yearsVal) % 4 == 0)
			{
				MonthesArray[NIXIE_MONTH_FEBFUARY] = 29;
				isGreatYear = true;
			}
			
			else MonthesArray[NIXIE_MONTH_FEBFUARY] = 28;
			
			if(*number < 1)
				*number = monthMaxVal;
			
			if(*number > monthMaxVal)
				*number = 1;
		break;
			
		case NIXIE_PAIR_SECOND:
			if(*number < 1)
				*number = 12;
			
			if(*number > 12)
				*number = 1;
			
			intVal = MonthesArray[*number - 1];
			
			if(DataDisplay_GetNumberFromArr(lampArr, &daysVal) - intVal > 0)
				DataDisplay_SetNumberToArr(lampArr, &intVal, &daysVal);
			
		break;
			
		case NIXIE_PAIR_THIRD:
			if(*number < 20)
				*number = 99;
			
			if(*number > 99)
				*number = 20;
			
			if(DataDisplay_GetNumberFromArr(lampArr, &monthVal) - 1 == NIXIE_MONTH_FEBFUARY)
			{
				if(isGreatYear == true)
				{
					if(MonthesArray[NIXIE_MONTH_FEBFUARY] == 29)
						MonthesArray[NIXIE_MONTH_FEBFUARY] = 28;
				}
				
				else MonthesArray[NIXIE_MONTH_FEBFUARY] = 28;
				
				intVal = MonthesArray[NIXIE_MONTH_FEBFUARY];
				DataDisplay_SetNumberToArr(lampArr, &intVal, &daysVal);
			}
		break;		
	}
}
/*========================================================================================================*/

/*========================================= DataDisplay_BlinkLamps =======================================*/

static void DataDisplay_BlinkLamps(uint8_t* lampArr, const uint8_t* lamp)
{
	static uint8_t dataBuffer[2];
	static uint8_t oldData;
	
	dataBuffer[0] = lampArr[*lamp];
	dataBuffer[1] = lampArr[*lamp + 1];
	
	if(Delay_SetBlink(NIXIE_BLINK_TIME) == false)
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
/*========================================================================================================*/

/*======================================== DataDisplay_ChangeBlink =======================================*/

static uint8_t DataDisplay_ChangeBlink(uint8_t* lampArr, const buttonCommands* command)
{
	static uint8_t lampsCounter;
	
	if(FirstRead == true)
	{
		lampsCounter = 0;
		FirstRead = false;
	}
	
	if(*command == COMMAND_MODE && FirstRead == false)
	{
		lampsCounter +=2;
		
		if(lampsCounter > 5)
			lampsCounter = 0;
	}
	
	if(EditState == false)
		DataDisplay_BlinkLamps(lampArr, &lampsCounter);
	
	return lampsCounter;
}
/*========================================================================================================*/

/*========================================= DataDisplay_EditTime =========================================*/
nixieActions DataDisplay_EditTime(buttonCommands command)
{
	nixieActions action = NIXIE_ACTION_IS_EDITING_TIME;
	uint8_t lampsArr[DYNAMIC_NUM_OF_LAMPS];
	int8_t lampsPairNumber;
	uint8_t lampsCounter;
	static uint16_t stickUpdateCounter;

	if(FirstRead == true)
 	{
		DS3231_ReadTime(&TimeStruct);
		EditState = false;
		command = COMMAND_NOBUTTON;
	}
	
	DataDisplay_DissasembleTime(lampsArr, &TimeStruct);
	lampsCounter = DataDisplay_ChangeBlink(lampsArr, &command);
	
	if(command == COMMAND_INCREASING || command == COMMAND_DECREASING || command == COMMAND_STICK_DECREASING || command == COMMAND_STICK_INCREASING)
	{
		DataDisplay_DissasembleTime(lampsArr, &TimeStruct);
		lampsPairNumber = DataDisplay_GetNumberFromArr(lampsArr, &lampsCounter);
		EditState = true;
		
		if(command == COMMAND_STICK_DECREASING || command == COMMAND_STICK_INCREASING)
		{
			if(Delay_GetTickVal())
				stickUpdateCounter++;
		}
		
		switch(command)
		{
			case COMMAND_INCREASING:
				lampsPairNumber++;
			break;
		
			case COMMAND_DECREASING:
				lampsPairNumber--;
			break;
			
			case COMMAND_STICK_INCREASING:
				if(stickUpdateCounter == NIXIE_UPDATE_VAL)
				{
					stickUpdateCounter = 0;
					lampsPairNumber++;
				}
			break;
				
			case COMMAND_STICK_DECREASING:
				if(stickUpdateCounter == NIXIE_UPDATE_VAL)
				{
					stickUpdateCounter = 0;
					lampsPairNumber--;
				}
			break;
				
			default:
			break;
		}
		
		DataDisplay_CheckTimeValidation(&lampsPairNumber, &lampsCounter);
		DataDisplay_SetNumberToArr(lampsArr, &lampsPairNumber, &lampsCounter);
		DataDisplay_SaveTimeCnanges(&TimeStruct, lampsArr);
	}
	
	if(command == COMMAND_NOBUTTON)
		EditState = false;
	
	if(ButtonIsPressed == false)
		command = COMMAND_NOBUTTON;
	
	if(command == COMMAND_SAVE_CHANGES)
	{
		DS3231_WriteTime(&TimeStruct);
		FirstRead = true;
		action = NIXIE_ACTION_END_OF_TIME_EDIT;
		NumOfLongClicks = 0;
	}
	
	Dynamic_ParseArr(lampsArr, DYNAMIC_ANIMATION_NONE);
	
	return action;
}
/*========================================================================================================*/

/*========================================= DataDisplay_EditDate =========================================*/
nixieActions DataDisplay_EditDate(buttonCommands command)
{
	nixieActions action = NIXIE_ACTION_IS_EDITING_DATE;
	uint8_t lampsArr[DYNAMIC_NUM_OF_LAMPS];
	int8_t lampsPairNumber;
	uint8_t lampsCounter;
	static uint16_t stickUpdateCounter;

	if(FirstRead == true)
 	{
		DS3231_ReadDate(&DateStruct);
		EditState = false;
		command = COMMAND_NOBUTTON;
	}
	
	DataDisplay_DissasembleDate(lampsArr, &DateStruct);
	lampsCounter = DataDisplay_ChangeBlink(lampsArr, &command);
	
	if(command == COMMAND_INCREASING || command == COMMAND_DECREASING || command == COMMAND_STICK_DECREASING || command == COMMAND_STICK_INCREASING)
	{
		DataDisplay_DissasembleDate(lampsArr, &DateStruct);
		lampsPairNumber = DataDisplay_GetNumberFromArr(lampsArr, &lampsCounter);
		EditState = true;
		
		if(command == COMMAND_STICK_DECREASING || command == COMMAND_STICK_INCREASING)
		{
			if(Delay_GetTickVal())
				stickUpdateCounter++;
		}
		
		switch(command)
		{
			case COMMAND_INCREASING:
				lampsPairNumber++;
			break;
		
			case COMMAND_DECREASING:
				lampsPairNumber--;
			break;
			
			case COMMAND_STICK_INCREASING:
				if(stickUpdateCounter == NIXIE_UPDATE_VAL)
				{
					stickUpdateCounter = 0;
					lampsPairNumber++;
				}
			break;
				
			case COMMAND_STICK_DECREASING:
				if(stickUpdateCounter == NIXIE_UPDATE_VAL)
				{
					stickUpdateCounter = 0;
					lampsPairNumber--;
				}
			break;
				
			default:
			break;
		}
		
		DataDisplay_CheckDateValidation(lampsArr, &lampsPairNumber, &lampsCounter);
		DataDisplay_SetNumberToArr(lampsArr, &lampsPairNumber, &lampsCounter);
		DataDisplay_SaveDateCnanges(&DateStruct, lampsArr);
	}
	
	if(command == COMMAND_NOBUTTON)
		EditState = false;
	
	if(ButtonIsPressed == false)
		command = COMMAND_NOBUTTON;
	
	if(command == COMMAND_SAVE_CHANGES)
	{
		DS3231_WriteDate(&DateStruct);
		FirstRead = true;
		action = NIXIE_ACTION_END_OF_DATE_EDIT;
		NumOfLongClicks = 0;
	}
	
	Dynamic_ParseArr(lampsArr, DYNAMIC_ANIMATION_NONE);
	
	return action;
}
/*========================================================================================================*/
