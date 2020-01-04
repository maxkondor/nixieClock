#include "GPIO_Config.h"

void GPIO_Config(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

	GPIO_InitTypeDef 										GPIO_Struct;

	/*====================== NIXIE TUBES SECTION =====================*/

	GPIO_Struct.GPIO_Mode 							= GPIO_Mode_Out_PP;
	GPIO_Struct.GPIO_Pin 								= GPIO_LAMP1_PIN |
																				GPIO_LAMP2_PIN |
																				GPIO_LAMP3_PIN |
																				GPIO_LAMP4_PIN |
																				GPIO_LAMP5_PIN |
																				GPIO_LAMP6_PIN;
	GPIO_Struct.GPIO_Speed 							= GPIO_Speed_10MHz;

	GPIO_Init(GPIO_LAMPS_PORT, &GPIO_Struct);
	/*================================================================*/

	/*======================= DECODER SECTION ========================*/

	GPIO_Struct.GPIO_Mode 							= GPIO_Mode_Out_PP;
	GPIO_Struct.GPIO_Pin    						= GPIO_DECODER_A0_PIN |
																				GPIO_DECODER_A1_PIN |
																				GPIO_DECODER_A2_PIN |
																				GPIO_DECODER_A3_PIN;
	GPIO_Struct.GPIO_Speed							= GPIO_Speed_10MHz;

	GPIO_Init(GPIO_DECODER_PORT, &GPIO_Struct);
	/*================================================================*/

	/*======================= BUTTONS SECTION ========================*/

	GPIO_Struct.GPIO_Mode 							= GPIO_Mode_IPU;
	GPIO_Struct.GPIO_Pin 								= GPIO_BUTTON1_PIN |
																				GPIO_BUTTON2_PIN |
																				GPIO_BUTTON3_PIN;
	GPIO_Struct.GPIO_Speed 							= GPIO_Speed_10MHz;

	GPIO_Init(GPIO_BUTTONS_PORT, &GPIO_Struct);
	/*================================================================*/

	/*======================= DS3231 SECTION =========================*/

	GPIO_Struct.GPIO_Mode								= GPIO_Mode_AF_OD;
	GPIO_Struct.GPIO_Pin								= GPIO_DS3231_SCL_PIN |
																				GPIO_DS3231_SDA_PIN;
	GPIO_Struct.GPIO_Speed							= GPIO_Speed_10MHz;

	GPIO_Init(GPIO_DS3231_PORT, &GPIO_Struct);
	/*================================================================*/
}
