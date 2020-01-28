#include "TIM_Config.h"

TIM_HandleTypeDef 																					TimerHandler;
TIM_HandleTypeDef																						DelayTimerHandler;


void TIM_Config(void)
{
	/*======================================= TIM2 Init ============================================*/

	__HAL_RCC_TIM2_CLK_ENABLE();

	TIM_ClockConfigTypeDef 																		sClockSourceConfig 	= {0};
  TIM_MasterConfigTypeDef 																	sMasterConfig 			= {0};

  TimerHandler.Instance 																		= TIM2;
  TimerHandler.Init.Prescaler 															= NIXIE_TIM_PRESCALLER;
  TimerHandler.Init.CounterMode 														= TIM_COUNTERMODE_UP;
  TimerHandler.Init.Period 																	= NIXIE_TIM_PERIOD;
  TimerHandler.Init.ClockDivision 													= TIM_CLOCKDIVISION_DIV1;
  TimerHandler.Init.AutoReloadPreload 											= TIM_AUTORELOAD_PRELOAD_DISABLE;

  HAL_TIM_Base_Init(&TimerHandler);

  sClockSourceConfig.ClockSource 														= TIM_CLOCKSOURCE_INTERNAL;

  HAL_TIM_ConfigClockSource(&TimerHandler, &sClockSourceConfig);

  sMasterConfig.MasterOutputTrigger 												= TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode 														= TIM_MASTERSLAVEMODE_DISABLE;

  HAL_TIMEx_MasterConfigSynchronization(&TimerHandler, &sMasterConfig);

	HAL_NVIC_SetPriority(TIM2_IRQn, 2, 1);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);

	HAL_TIM_Base_Start_IT(&TimerHandler);
	/*==============================================================================================*/

	/*======================================= TIM3 Init ============================================*/

	__HAL_RCC_TIM3_CLK_ENABLE();

	DelayTimerHandler.Instance 																= TIM3;
  DelayTimerHandler.Init.Prescaler 													= NIXIE_DELAYTIM_PRESCALLER;
  DelayTimerHandler.Init.CounterMode 												= TIM_COUNTERMODE_UP;
  DelayTimerHandler.Init.Period 														= NIXIE_DELAYTIM_PERIOD;
  DelayTimerHandler.Init.ClockDivision 											= TIM_CLOCKDIVISION_DIV1;
  DelayTimerHandler.Init.AutoReloadPreload 									= TIM_AUTORELOAD_PRELOAD_DISABLE;

	HAL_TIM_Base_Init(&DelayTimerHandler);

	sClockSourceConfig.ClockSource 														= TIM_CLOCKSOURCE_INTERNAL;

  HAL_TIM_ConfigClockSource(&DelayTimerHandler, &sClockSourceConfig);

	sMasterConfig.MasterOutputTrigger 												= TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode 														= TIM_MASTERSLAVEMODE_DISABLE;

  HAL_TIMEx_MasterConfigSynchronization(&DelayTimerHandler, &sMasterConfig);

	HAL_NVIC_SetPriority(TIM3_IRQn, 2, 2);
  HAL_NVIC_EnableIRQ(TIM3_IRQn);
	
	HAL_TIM_Base_Start_IT(&DelayTimerHandler);
	/*==============================================================================================*/
}


void SysTick_Handler(void)
{
  HAL_IncTick();
}
