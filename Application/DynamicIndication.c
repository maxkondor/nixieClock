#include "DynamicIndication.h"
#include "DynamicIndicationMacrocces.h"
#include "TIM_Config.h"

uint8_t GlobalLampsArr[6];

void ShowSimpleDigit(uint8_t *digit);
void DynamicShow(uint8_t *nixieArr);
uint8_t DynamicCounter(DynamicCounterState state);

/*=========================== TIM2 Interrupt Handler ===========================*/

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TimerHandler);
	DynamicShow(GlobalLampsArr);
}
/*==============================================================================*/

void ShowSimpleDigit(uint8_t *digit)
{
	switch(*digit)
	{
		case 0:
			NIXIE_DECODER_ZERO;
		break;
		
		case 1:
			NIXIE_DECODER_ONE;
		break;
		
		case 2:
			NIXIE_DECODER_TWO;
		break;
		
		case 3:
			NIXIE_DECODER_THREE;
		break;
		
		case 4:
			NIXIE_DECODER_FOUR;
		break;
		
		case 5:
			NIXIE_DECODER_FIVE;
		break;
		
		case 6:
			NIXIE_DECODER_SIX;
		break;
		
		case 7:
			NIXIE_DECODER_SEVEN;
		break;
		
		case 8:
			NIXIE_DECODER_EIGHT;
		break;
		
		case 9:
			NIXIE_DECODER_NINE;
		break;
	}
}

void DynamicShow(uint8_t nixieArr[6])
{
	switch(DynamicCounter(GETVal))
	{
		case 0:
			NIXIE_ONLY_1ST_LAMP_ON;
			ShowSimpleDigit(&nixieArr[0]);
		break;
		
		case 1:
			NIXIE_ONLY_2ND_LAMP_ON;
			ShowSimpleDigit(&nixieArr[1]);
		break;
		
		case 2:
			NIXIE_ONLY_3RD_LAMP_ON;
			ShowSimpleDigit(&nixieArr[2]);
		break;
		
		case 3:
			NIXIE_ONLY_4TH_LAMP_ON;
			ShowSimpleDigit(&nixieArr[3]);
		break;
		
		case 4:
			NIXIE_ONLY_5TH_LAMP_ON;
			ShowSimpleDigit(&nixieArr[4]);
		break;
		
		case 5:
			NIXIE_ONLY_6TH_LAMP_ON;
			ShowSimpleDigit(&nixieArr[5]);
		break;
	}
	
	DynamicCounter(SETVal);
}

uint8_t DynamicCounter(DynamicCounterState state)
{
	static uint8_t counter;
	
	if(state != GETVal)
	{
		counter > 4 ? counter = 0 : counter++;
	}
	
	return counter;
}

void Nixie_ShowArr(uint8_t arr[6])
{
	memcpy(GlobalLampsArr, arr, 6);
}
