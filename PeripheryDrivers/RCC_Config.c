#include "RCC_Config.h"

void RCC_Config(void)
{
	ErrorStatus HSEStartUpStatus;

	RCC_DeInit();
	RCC_HSEConfig( RCC_HSE_ON);

	HSEStartUpStatus = RCC_WaitForHSEStartUp();

	if (HSEStartUpStatus == SUCCESS)
	{
		RCC_HCLKConfig( RCC_SYSCLK_Div1);
		RCC_PCLK2Config( RCC_HCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div1);
		RCC_SYSCLKConfig( RCC_SYSCLKSource_HSE);
	
		while (RCC_GetSYSCLKSource() != 0x04)
		{
		}
	}
	else
	{
		while (1)
		{
		}
	}
}
