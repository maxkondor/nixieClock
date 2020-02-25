#include "DynamicIndication.h"
#include "DynamicIndicationMacrocces.h"
#include "TIM_Config.h"
#include "Delay.h"

typedef enum{
	
	GETVal,
	SETVal
	
}Dynamic_CounterState;

bool DelayTimRst = false;
uint8_t GlobalLampsArr[6];
uint8_t Dynamic_Counter(Dynamic_CounterState state);

void Dynamic_ShowSimpleDigit(uint8_t *digit);
void Dynamic_ShowArr(uint8_t* nixieArr);

void Dynamic_Animation_None(uint8_t* nixieArr);
void Dynamic_Animation_AllDigits(uint8_t* nixieArr);



/*=========================== TIM2 Interrupt Handler ===========================*/

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&IndicationTimerHandler);
	Dynamic_ShowArr(GlobalLampsArr);
}
/*==============================================================================*/

void Dynamic_ShowSimpleDigit(uint8_t *digit)
{
	switch(*digit)
	{
		case 0:
			DYNAMIC_DECODER_ZERO;
		break;
		
		case 1:
			DYNAMIC_DECODER_ONE;
		break;
		
		case 2:
			DYNAMIC_DECODER_TWO;
		break;
		
		case 3:
			DYNAMIC_DECODER_THREE;
		break;
		
		case 4:
			DYNAMIC_DECODER_FOUR;
		break;
		
		case 5:
			DYNAMIC_DECODER_FIVE;
		break;
		
		case 6:
			DYNAMIC_DECODER_SIX;
		break;
		
		case 7:
			DYNAMIC_DECODER_SEVEN;
		break;
		
		case 8:
			DYNAMIC_DECODER_EIGHT;
		break;
		
		case 9:
			DYNAMIC_DECODER_NINE;
		break;
		
		case 10:
			DYNAMIC_DECODER_OFF;
		break;
	}
}

void Dynamic_ShowArr(uint8_t* nixieArr)
{
	switch(Dynamic_Counter(GETVal))
	{
		case 0:
			DYNAMIC_ONLY_1ST_LAMP_ON;
			Dynamic_ShowSimpleDigit(&nixieArr[0]);
		break;
		
		case 1:
			DYNAMIC_ONLY_2ND_LAMP_ON;
			Dynamic_ShowSimpleDigit(&nixieArr[1]);
		break;
		
		case 2:
			DYNAMIC_ONLY_3RD_LAMP_ON;
			Dynamic_ShowSimpleDigit(&nixieArr[2]);
		break;
		
		case 3:
			DYNAMIC_ONLY_4TH_LAMP_ON;
			Dynamic_ShowSimpleDigit(&nixieArr[3]);
		break;
		
		case 4:
			DYNAMIC_ONLY_5TH_LAMP_ON;
			Dynamic_ShowSimpleDigit(&nixieArr[4]);
		break;
		
		case 5:
			DYNAMIC_ONLY_6TH_LAMP_ON;
			Dynamic_ShowSimpleDigit(&nixieArr[5]);
		break;
	}
	
	Dynamic_Counter(SETVal);
}

uint8_t Dynamic_Counter(Dynamic_CounterState state)
{
	static uint8_t counter;
	
	if(state != GETVal)
	{
		counter > 4 ? counter = 0 : counter++;
	}
	
	return counter;
}

void Dynamic_ParseArr(uint8_t* arr, dynamicAnimations animType)
{
	if(animType == DYNAMIC_ANIMATION_NONE)
		Dynamic_Animation_None(arr);
	
	else if(animType == DYNAMIC_ANIMATION_ALL_DIGITS)
		Dynamic_Animation_AllDigits(arr);
}

void Dynamic_Animation_AllDigits(uint8_t* nixieArr)
{
	static uint8_t oldData;

	if(oldData != nixieArr[5])
	{
		for(uint8_t lampsNumb = 0; lampsNumb < 6; lampsNumb++)
		{
			for(uint8_t digit = 0; digit < 10; digit++)
			{
				GlobalLampsArr[lampsNumb] = digit;
				HAL_Delay(DYNAMIC_ANIMAION_DELAY);
			}
			
			GlobalLampsArr[lampsNumb] = nixieArr[lampsNumb];
		}
	}
	
	oldData = nixieArr[5];
}

void Dynamic_Animation_None(uint8_t* nixieArr)
{
	memcpy(GlobalLampsArr, nixieArr, DYNAMIC_NUM_OF_LAMPS);
}

void Dynamic_BlinkOneLamp(uint8_t lamp)
{
	
	
	switch(lamp)
	{
		case 1:
			DYNAMIC_ONLY_1ST_LAMP_ON;
		break;
		
		case 2:
			DYNAMIC_ONLY_2ND_LAMP_ON;
		break;
		
		case 3:
			DYNAMIC_ONLY_3RD_LAMP_ON;
		break;
		
		case 4:
			DYNAMIC_ONLY_4TH_LAMP_ON;
		break;
		
		case 5:
			DYNAMIC_ONLY_5TH_LAMP_ON;
		break;
		
		case 6:
			DYNAMIC_ONLY_6TH_LAMP_ON;
		
	}
}


