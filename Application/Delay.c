#include "Delay.h"
#include "TIM_Config.h"
#include "ButtonsInput.h"

uint16_t 												Counter = 0;
bool 														TimerUpdate;
extern bool 										ButtonIsPressed;
uint16_t 												PressedCounter;

bool Delay_SetBlink(uint16_t delayVal)
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
	
	if(oldData != TimerUpdate)
		tickVal = true;
	
	oldData = TimerUpdate;
	
	return tickVal;
}

uint16_t Delay_GetPressedCounter(void)
{
	return PressedCounter;
}

/*===================================== TIM3 Interrupt Handler ===================================*/

void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&CounterTimerHandler);

	if(TimerUpdate == true)
		TimerUpdate = false;
	
	else TimerUpdate = true;
	
	if(ButtonIsPressed)
		PressedCounter++;
	
	else PressedCounter = 0;
}
/*================================================================================================*/
