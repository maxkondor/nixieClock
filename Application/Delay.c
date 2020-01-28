#include "Delay.h"

uint16_t Counter = 0;

bool Delay_NoPause(uint16_t delayVal)
{
	static uint32_t oldData;
	
	bool tickVal;
	
	if(oldData != HAL_GetTick())
		Counter++;
		
	if(Counter < delayVal / 2)
		tickVal = true;
	
	else if(Counter >= delayVal / 2 && Counter < delayVal)
		tickVal = false;
	
	else Counter = 0;
	
	oldData = HAL_GetTick();
	
	return tickVal;
}

void Delay_ResetCounter(void)
{
	Counter = 0;
}

bool Delay_GetTickVal(void)
{
	static uint32_t oldData;
	bool tickVal = false;
	
	if(oldData != HAL_GetTick())
		tickVal = true;
	
	oldData = HAL_GetTick();
	
	return tickVal;
}
