#include "RCC_Config.h"
#include "GPIO_Config.h"
#include "TIM_Config.h"
#include "I2C_Config.h"
#include "DynamicIndication.h"


int main (void)
{
	RCC_Config();
	GPIO_Config();
	TIM_Config();
	I2C_Config();
	
	uint8_t arr[6];
	
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	arr[5] = 6;
	
	Nixie_ShowArr(arr);
	
	uint8_t data = 0;
	
	data = I2C_ReadData(0x00);
	
	while(1)
	{
	
	}
}
