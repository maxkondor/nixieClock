#ifndef DYNAMICINDICATIONMACROCCES_H
#define DYNAMICINDICATIONMACROCCES_H

#include "GPIO_Config.h"

/*============================================= NIXIE TUBES SECTION ===============================================*/

#define DYNAMIC_LAMP1_ENABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP1_PIN, GPIO_PIN_SET)							
#define DYNAMIC_LAMP1_DISABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP1_PIN, GPIO_PIN_RESET)	

#define DYNAMIC_LAMP2_ENABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP2_PIN, GPIO_PIN_SET)	
#define DYNAMIC_LAMP2_DISABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP2_PIN, GPIO_PIN_RESET)	

#define DYNAMIC_LAMP3_ENABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP3_PIN, GPIO_PIN_SET)	
#define DYNAMIC_LAMP3_DISABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP3_PIN, GPIO_PIN_RESET)	

#define DYNAMIC_LAMP4_ENABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP4_PIN, GPIO_PIN_SET)	
#define DYNAMIC_LAMP4_DISABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP4_PIN, GPIO_PIN_RESET)	

#define DYNAMIC_LAMP5_ENABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP5_PIN, GPIO_PIN_SET)	
#define DYNAMIC_LAMP5_DISABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP5_PIN, GPIO_PIN_RESET)	

#define DYNAMIC_LAMP6_ENABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP6_PIN, GPIO_PIN_SET)	
#define DYNAMIC_LAMP6_DISABLE						HAL_GPIO_WritePin(GPIO_LAMPS_PORT, GPIO_LAMP6_PIN, GPIO_PIN_RESET)	
/*=================================================================================================================*/

/*=============================================== DECODER SECTION =================================================*/

#define DYNAMIC_DECODER_A0_ENABLE				HAL_GPIO_WritePin(GPIO_DECODER_PORT, GPIO_DECODER_A0_PIN, GPIO_PIN_SET)
#define DYNAMIC_DECODER_A0_DISABLE			HAL_GPIO_WritePin(GPIO_DECODER_PORT, GPIO_DECODER_A0_PIN, GPIO_PIN_RESET)

#define DYNAMIC_DECODER_A1_ENABLE				HAL_GPIO_WritePin(GPIO_DECODER_PORT, GPIO_DECODER_A1_PIN, GPIO_PIN_SET)
#define DYNAMIC_DECODER_A1_DISABLE			HAL_GPIO_WritePin(GPIO_DECODER_PORT, GPIO_DECODER_A1_PIN, GPIO_PIN_RESET)

#define DYNAMIC_DECODER_A2_ENABLE				HAL_GPIO_WritePin(GPIO_DECODER_PORT, GPIO_DECODER_A2_PIN, GPIO_PIN_SET)
#define DYNAMIC_DECODER_A2_DISABLE			HAL_GPIO_WritePin(GPIO_DECODER_PORT, GPIO_DECODER_A2_PIN, GPIO_PIN_RESET)

#define DYNAMIC_DECODER_A3_ENABLE				HAL_GPIO_WritePin(GPIO_DECODER_PORT, GPIO_DECODER_A3_PIN, GPIO_PIN_SET)
#define DYNAMIC_DECODER_A3_DISABLE			HAL_GPIO_WritePin(GPIO_DECODER_PORT, GPIO_DECODER_A3_PIN, GPIO_PIN_RESET)
/*=================================================================================================================*/

/*======================================== DECODER DIGITS SECTION =========================================*/

#define DYNAMIC_DECODER_ZERO						DYNAMIC_DECODER_A0_DISABLE; \
																				DYNAMIC_DECODER_A1_DISABLE; \
																				DYNAMIC_DECODER_A2_DISABLE; \
																				DYNAMIC_DECODER_A3_DISABLE;
																		
#define DYNAMIC_DECODER_ONE							DYNAMIC_DECODER_A0_ENABLE;  \
																				DYNAMIC_DECODER_A1_DISABLE; \
																				DYNAMIC_DECODER_A2_DISABLE; \
																				DYNAMIC_DECODER_A3_DISABLE;
																			
#define DYNAMIC_DECODER_TWO							DYNAMIC_DECODER_A0_DISABLE; \
																				DYNAMIC_DECODER_A1_ENABLE;  \
																				DYNAMIC_DECODER_A2_DISABLE; \
																				DYNAMIC_DECODER_A3_DISABLE;
																			
#define DYNAMIC_DECODER_THREE						DYNAMIC_DECODER_A0_ENABLE;  \
																				DYNAMIC_DECODER_A1_ENABLE;  \
																				DYNAMIC_DECODER_A2_DISABLE; \
																				DYNAMIC_DECODER_A3_DISABLE;
																			
#define DYNAMIC_DECODER_FOUR						DYNAMIC_DECODER_A0_DISABLE; \
																				DYNAMIC_DECODER_A1_DISABLE; \
																				DYNAMIC_DECODER_A2_ENABLE;  \
																				DYNAMIC_DECODER_A3_DISABLE;				

#define DYNAMIC_DECODER_FIVE						DYNAMIC_DECODER_A0_ENABLE;  \
																				DYNAMIC_DECODER_A1_DISABLE; \
																				DYNAMIC_DECODER_A2_ENABLE;  \
																				DYNAMIC_DECODER_A3_DISABLE;
																			
#define DYNAMIC_DECODER_SIX							DYNAMIC_DECODER_A0_DISABLE; \
																				DYNAMIC_DECODER_A1_ENABLE;  \
																				DYNAMIC_DECODER_A2_ENABLE;  \
																				DYNAMIC_DECODER_A3_DISABLE;		

#define DYNAMIC_DECODER_SEVEN						DYNAMIC_DECODER_A0_ENABLE;  \
																				DYNAMIC_DECODER_A1_ENABLE;  \
																				DYNAMIC_DECODER_A2_ENABLE;  \
																				DYNAMIC_DECODER_A3_DISABLE;
																			
#define DYNAMIC_DECODER_EIGHT						DYNAMIC_DECODER_A0_DISABLE; \
																				DYNAMIC_DECODER_A1_DISABLE; \
																				DYNAMIC_DECODER_A2_DISABLE; \
																				DYNAMIC_DECODER_A3_ENABLE;	

#define DYNAMIC_DECODER_NINE						DYNAMIC_DECODER_A0_ENABLE;  \
																				DYNAMIC_DECODER_A1_DISABLE; \
																				DYNAMIC_DECODER_A2_DISABLE; \
																				DYNAMIC_DECODER_A3_ENABLE;
																				
#define DYNAMIC_DECODER_OFF							DYNAMIC_DECODER_A0_ENABLE;  \
																				DYNAMIC_DECODER_A1_ENABLE;  \
																				DYNAMIC_DECODER_A2_ENABLE;  \
																				DYNAMIC_DECODER_A3_ENABLE;		
/*=========================================================================================================*/

/*===================================== NIXIE ONE LAMP VALUE SECTION ======================================*/

#define DYNAMIC_ONLY_1ST_LAMP_ON				DYNAMIC_LAMP1_ENABLE; \
																				DYNAMIC_LAMP2_DISABLE;\
																				DYNAMIC_LAMP3_DISABLE;\
																				DYNAMIC_LAMP4_DISABLE;\
																				DYNAMIC_LAMP5_DISABLE;\
																				DYNAMIC_LAMP6_DISABLE;

#define DYNAMIC_ONLY_2ND_LAMP_ON				DYNAMIC_LAMP1_DISABLE;\
																				DYNAMIC_LAMP2_ENABLE; \
																				DYNAMIC_LAMP3_DISABLE;\
																				DYNAMIC_LAMP4_DISABLE;\
																				DYNAMIC_LAMP5_DISABLE;\
																				DYNAMIC_LAMP6_DISABLE;

#define DYNAMIC_ONLY_3RD_LAMP_ON				DYNAMIC_LAMP1_DISABLE;\
																				DYNAMIC_LAMP2_DISABLE;\
																				DYNAMIC_LAMP3_ENABLE; \
																				DYNAMIC_LAMP4_DISABLE;\
																				DYNAMIC_LAMP5_DISABLE;\
																				DYNAMIC_LAMP6_DISABLE;
																			
#define DYNAMIC_ONLY_4TH_LAMP_ON				DYNAMIC_LAMP1_DISABLE;\
																				DYNAMIC_LAMP2_DISABLE;\
																				DYNAMIC_LAMP3_DISABLE;\
																				DYNAMIC_LAMP4_ENABLE; \
																				DYNAMIC_LAMP5_DISABLE;\
																				DYNAMIC_LAMP6_DISABLE;
																			
#define DYNAMIC_ONLY_5TH_LAMP_ON				DYNAMIC_LAMP1_DISABLE;\
																				DYNAMIC_LAMP2_DISABLE;\
																				DYNAMIC_LAMP3_DISABLE;\
																				DYNAMIC_LAMP4_DISABLE;\
																				DYNAMIC_LAMP5_ENABLE; \
																				DYNAMIC_LAMP6_DISABLE;
																			
#define DYNAMIC_ONLY_6TH_LAMP_ON				DYNAMIC_LAMP1_DISABLE;\
																				DYNAMIC_LAMP2_DISABLE;\
																				DYNAMIC_LAMP3_DISABLE;\
																				DYNAMIC_LAMP4_DISABLE;\
																				DYNAMIC_LAMP5_DISABLE;\
																				DYNAMIC_LAMP6_ENABLE;
																				
#define DYNAMIC_ALL_LAMPS_OFF						DYNAMIC_LAMP1_DISABLE;\
																				DYNAMIC_LAMP2_DISABLE;\
																				DYNAMIC_LAMP3_DISABLE;\
																				DYNAMIC_LAMP4_DISABLE;\
																				DYNAMIC_LAMP5_DISABLE;\
																				DYNAMIC_LAMP6_DISABLE
/*=========================================================================================================*/

#endif  // DYNAMICINDICATION_H
