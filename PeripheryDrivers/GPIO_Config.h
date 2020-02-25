#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#include "stm32f1xx_hal.h"

/*====================== NIXIE TUBES SECTION =====================*/

#define GPIO_LAMPS_PORT									GPIOA

#define GPIO_LAMP1_PIN									GPIO_PIN_6
#define GPIO_LAMP2_PIN									GPIO_PIN_7
#define GPIO_LAMP3_PIN									GPIO_PIN_11
#define GPIO_LAMP4_PIN									GPIO_PIN_10
#define GPIO_LAMP5_PIN									GPIO_PIN_9
#define GPIO_LAMP6_PIN									GPIO_PIN_8
/*================================================================*/

/*======================= DECODER SECTION ========================*/

#define GPIO_DECODER_PORT								GPIOB

#define GPIO_DECODER_A0_PIN							GPIO_PIN_1
#define GPIO_DECODER_A1_PIN							GPIO_PIN_2
#define GPIO_DECODER_A2_PIN							GPIO_PIN_3
#define GPIO_DECODER_A3_PIN							GPIO_PIN_4
/*================================================================*/

/*======================= BUTTONS SECTION ========================*/

#define GPIO_BUTTONS_PORT								GPIOB

#define GPIO_BUTTON1_PIN								GPIO_PIN_12
#define GPIO_BUTTON2_PIN								GPIO_PIN_11
#define GPIO_BUTTON3_PIN								GPIO_PIN_10
/*================================================================*/

/*======================= DS3231 SECTION =========================*/

#define GPIO_DS3231_PORT								GPIOB

#define GPIO_DS3231_SDA_PIN							GPIO_PIN_7
#define GPIO_DS3231_SCL_PIN							GPIO_PIN_6
/*================================================================*/

/*=======================TEST LED SECTION=========================*/

#define GPIO_TEST_LED_PORT							GPIOC

#define GPIO_TEST_LED_PIN								GPIO_PIN_13
/*================================================================*/

void GPIO_Config(void);


#endif 	// GPIO_CONFIG_H
