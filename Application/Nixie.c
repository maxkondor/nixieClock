#include "Nixie.h"

bool endOfAnimation;

typedef enum{
	
	NIXIE_ARR_HOURS_TENS = 0,
	NIXIE_ARR_HOURS_UNITS,
	
	NIXIE_ARR_MINUTES_TENS,
	NIXIE_ARR_MINUTES_UNITS,
	
	NIXIE_ARR_SECONDS_TENS,
	NIXIE_ARR_SECONDS_UNITS,
	
}nixieArrDigits;

uint8_t* Nixie_ShowAnimationDigit(uint8_t* lampsArr);
void Nixie_ShowAnimationV2(uint8_t* arrForAnimate);

void Nixie_ShowTime(void)
{
	uint8_t lampsArr[DYNAMIC_NUM_OF_LAMPS];
	
	ds3231_str timeStruct;
	
	DS3231_ReadData(&timeStruct);
	
	lampsArr[NIXIE_ARR_HOURS_TENS] = timeStruct.hours / 10;
	lampsArr[NIXIE_ARR_HOURS_UNITS] = timeStruct.hours % 10;
	
	lampsArr[NIXIE_ARR_MINUTES_TENS] = timeStruct.minutes / 10;
	lampsArr[NIXIE_ARR_MINUTES_UNITS] = timeStruct.minutes % 10;
	
	lampsArr[NIXIE_ARR_SECONDS_TENS] = timeStruct.seconds / 10;
	lampsArr[NIXIE_ARR_SECONDS_UNITS] = timeStruct.seconds % 10;
	
	Dynamic_ParseArr(lampsArr, DYNAMIC_ANIMATION_ALL_DIGITS);
}
