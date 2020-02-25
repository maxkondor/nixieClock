#include "DataDisplay.h"
#include "DataEditor.h"



/*========================================= DataDisplay_ShowTime =========================================*/

nixieActions DataDisplay_ShowTime(dynamicAnimations animType)
{
	nixieActions action = NIXIE_ACTION_IS_SHOWING_TIME;
	
	uint8_t lampsArr[DYNAMIC_NUM_OF_LAMPS];
	ds3231_timeStruct timeStruct;
	
	DS3231_ReadTime(&timeStruct);
	DataDisplay_DissasembleTime(lampsArr, &timeStruct);
	Dynamic_ParseArr(lampsArr, animType);
	
	return action;
}
/*========================================================================================================*/

/*========================================= DataDisplay_ShowDate =========================================*/

nixieActions DataDisplay_ShowDate(dynamicAnimations animType)
{
	nixieActions action = NIXIE_ACTION_IS_SHOWING_DATE;
	
	uint8_t lampsArr[DYNAMIC_NUM_OF_LAMPS];
	ds3231_dateStruct dateStruct;
	
	DS3231_ReadDate(&dateStruct);
	DataDisplay_DissasembleDate(lampsArr, &dateStruct);
	Dynamic_ParseArr(lampsArr, animType);
	
	return action;
}
/*========================================================================================================*/
