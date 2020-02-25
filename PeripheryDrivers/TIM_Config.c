#include "TIM_Config.h"

TIM_HandleTypeDef 																					IndicationTimerHandler;
TIM_HandleTypeDef																						CounterTimerHandler;

void TIM_Config(void)
{
	/*======================================= TIM2 Init ============================================*/

	__HAL_RCC_TIM2_CLK_ENABLE();

	TIM_ClockConfigTypeDef 																		sClockSourceConfig 	= {0};
  TIM_MasterConfigTypeDef 																	sMasterConfig 			= {0};

  IndicationTimerHandler.Instance 													= TIM2;
  IndicationTimerHandler.Init.Prescaler 										= DataDisplay_TIM_PRESCALLER;
  IndicationTimerHandler.Init.CounterMode 									= TIM_COUNTERMODE_UP;
  IndicationTimerHandler.Init.Period 												= DataDisplay_TIM_PERIOD;
  IndicationTimerHandler.Init.ClockDivision 								= TIM_CLOCKDIVISION_DIV1;
  IndicationTimerHandler.Init.AutoReloadPreload 						= TIM_AUTORELOAD_PRELOAD_DISABLE;

  HAL_TIM_Base_Init(&IndicationTimerHandler);

  sClockSourceConfig.ClockSource 														= TIM_CLOCKSOURCE_INTERNAL;

  HAL_TIM_ConfigClockSource(&IndicationTimerHandler, &sClockSourceConfig);

  sMasterConfig.MasterOutputTrigger 												= TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode 														= TIM_MASTERSLAVEMODE_DISABLE;

  HAL_TIMEx_MasterConfigSynchronization(&IndicationTimerHandler, &sMasterConfig);

	HAL_NVIC_SetPriority(TIM2_IRQn, 2, 1);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);

	HAL_TIM_Base_Start_IT(&IndicationTimerHandler);
	/*==============================================================================================*/

	/*======================================= TIM3 Init ============================================*/

	__HAL_RCC_TIM3_CLK_ENABLE();

	CounterTimerHandler.Instance 															= TIM3;
  CounterTimerHandler.Init.Prescaler 												= DataDisplay_COUNTER_TIM_PRESCALLER;
  CounterTimerHandler.Init.CounterMode 											= TIM_COUNTERMODE_UP;
  CounterTimerHandler.Init.Period 													= DataDisplay_COUNTER_TIM_PERIOD;
  CounterTimerHandler.Init.ClockDivision 										= TIM_CLOCKDIVISION_DIV1;
  CounterTimerHandler.Init.AutoReloadPreload 								= TIM_AUTORELOAD_PRELOAD_DISABLE;

	HAL_TIM_Base_Init(&CounterTimerHandler);

	sClockSourceConfig.ClockSource 														= TIM_CLOCKSOURCE_INTERNAL;

  HAL_TIM_ConfigClockSource(&CounterTimerHandler, &sClockSourceConfig);

	sMasterConfig.MasterOutputTrigger 												= TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode 														= TIM_MASTERSLAVEMODE_DISABLE;

  HAL_TIMEx_MasterConfigSynchronization(&CounterTimerHandler, &sMasterConfig);

	HAL_NVIC_SetPriority(TIM3_IRQn, 2, 2);
  HAL_NVIC_EnableIRQ(TIM3_IRQn);
	
	HAL_TIM_Base_Start_IT(&CounterTimerHandler);
	/*==============================================================================================*/
}



void SysTick_Handler(void)
{
  HAL_IncTick();
}
