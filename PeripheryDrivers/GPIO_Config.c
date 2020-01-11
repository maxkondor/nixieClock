#include "GPIO_Config.h"

void GPIO_Config(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_AFIO_CLK_ENABLE();
	
	__HAL_AFIO_REMAP_SWJ_NOJTAG();

	GPIO_InitTypeDef 										GPIO_Struct;
	
	/*====================== NIXIE TUBES SECTION =====================*/

	GPIO_Struct.Mode										= GPIO_MODE_OUTPUT_PP;
	GPIO_Struct.Pin 										= GPIO_LAMP1_PIN |
																				GPIO_LAMP2_PIN |
																				GPIO_LAMP3_PIN |
																				GPIO_LAMP4_PIN |
																				GPIO_LAMP5_PIN |
																				GPIO_LAMP6_PIN;
	GPIO_Struct.Speed 									= GPIO_SPEED_FREQ_MEDIUM;

	HAL_GPIO_Init(GPIO_LAMPS_PORT, &GPIO_Struct);
	/*================================================================*/

	/*======================= DECODER SECTION ========================*/

	GPIO_Struct.Mode 										= GPIO_MODE_OUTPUT_PP;
	GPIO_Struct.Pin    									= GPIO_DECODER_A0_PIN |
																				GPIO_DECODER_A1_PIN |
																				GPIO_DECODER_A2_PIN |
																				GPIO_DECODER_A3_PIN;
	GPIO_Struct.Speed										= GPIO_SPEED_FREQ_MEDIUM;

	HAL_GPIO_Init(GPIO_DECODER_PORT, &GPIO_Struct);
	/*================================================================*/

	/*======================= BUTTONS SECTION ========================*/

	GPIO_Struct.Mode 										= GPIO_MODE_IT_RISING;
	GPIO_Struct.Pin 										= GPIO_BUTTON1_PIN |
																				GPIO_BUTTON2_PIN |
																				GPIO_BUTTON3_PIN;
	GPIO_Struct.Speed 									= GPIO_SPEED_FREQ_MEDIUM;
	GPIO_Struct.Pull										= GPIO_NOPULL;

	HAL_GPIO_Init(GPIO_BUTTONS_PORT, &GPIO_Struct);
	/*================================================================*/

	/*======================= DS3231 SECTION =========================*/

	GPIO_Struct.Mode										= GPIO_MODE_AF_OD;
	GPIO_Struct.Pin											= GPIO_DS3231_SCL_PIN |
																				GPIO_DS3231_SDA_PIN;
	GPIO_Struct.Speed										= GPIO_SPEED_FREQ_MEDIUM;
	 

	HAL_GPIO_Init(GPIO_DS3231_PORT, &GPIO_Struct);
	/*================================================================*/
}
