#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

/*====================== NIXIE TUBES SECTION =====================*/

#define GPIO_LAMPS_PORT									GPIOA

#define GPIO_LAMP1_PIN									GPIO_Pin_6
#define GPIO_LAMP2_PIN									GPIO_Pin_7
#define GPIO_LAMP3_PIN									GPIO_Pin_11
#define GPIO_LAMP4_PIN									GPIO_Pin_10
#define GPIO_LAMP5_PIN									GPIO_Pin_9
#define GPIO_LAMP6_PIN									GPIO_Pin_8
/*================================================================*/

/*======================= DECODER SECTION ========================*/

#define GPIO_DECODER_PORT								GPIOB

#define GPIO_DECODER_A0_PIN							GPIO_Pin_1
#define GPIO_DECODER_A1_PIN							GPIO_Pin_2
#define GPIO_DECODER_A2_PIN							GPIO_Pin_3
#define GPIO_DECODER_A3_PIN							GPIO_Pin_4
/*================================================================*/

/*======================= BUTTONS SECTION ========================*/

#define GPIO_BUTTONS_PORT								GPIOB

#define GPIO_BUTTON1_PIN								GPIO_Pin_12
#define GPIO_BUTTON2_PIN								GPIO_Pin_11
#define GPIO_BUTTON3_PIN								GPIO_Pin_10
/*================================================================*/

/*======================= DS3231 SECTION =========================*/

#define GPIO_DS3231_PORT								GPIOB

#define GPIO_DS3231_SDA_PIN							GPIO_Pin_7
#define GPIO_DS3231_SCL_PIN							GPIO_Pin_6
/*================================================================*/

void GPIO_Config(void);


#endif 	// GPIO_CONFIG_H
