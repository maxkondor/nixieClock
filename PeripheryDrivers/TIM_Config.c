#include "TIM_Config.h"

void TIM_Config(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitTypeDef 									TIM_Struct;
	NVIC_InitTypeDef 													NVIC_Struct;
	
	TIM_Struct.TIM_ClockDivision 							= TIM_CKD_DIV1;
	TIM_Struct.TIM_CounterMode 								= TIM_CounterMode_Up;
	TIM_Struct.TIM_Prescaler									= NIXIE_TIM_PRESCALLER - 1;
	TIM_Struct.TIM_Period											= NIXIE_TIM_PERIOD;
	TIM_Struct.TIM_RepetitionCounter 					= 0;
	
	TIM_TimeBaseInit(TIM2, &TIM_Struct);
	
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	
	
	NVIC_Struct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_Struct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_Struct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Struct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_Struct);
	
	TIM_Cmd(TIM2, ENABLE);
}
