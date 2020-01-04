#include "RCC_Config.h"
#include "GPIO_Config.h"
#include "TIM_Config.h"
#include "I2C_Config.h"
#include "DynamicIndication.h"

#include "DS3231.h"

int main (void)
{
	HAL_Init();
	RCC_Config();
	GPIO_Config();
	TIM_Config();
	I2C_Config();
	
	ds3231_str 	timeStruct;
	uint8_t 		lampsArr[6];
	
	while(1)
	{
		DS3231_ReadData(&timeStruct);
		
		lampsArr[0] = timeStruct.hours / 10;
		lampsArr[1] = timeStruct.hours % 10;
		
		lampsArr[2] = timeStruct.minutes / 10;
		lampsArr[3] = timeStruct.minutes % 10;
		
		lampsArr[4] = timeStruct.seconds / 10;
		lampsArr[5] = timeStruct.seconds % 10;
		
		Nixie_ShowArr(lampsArr);
	}
}
