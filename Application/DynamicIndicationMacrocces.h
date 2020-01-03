#ifndef DYNAMICINDICATIONMACROCCES_H
#define DYNAMICINDICATIONMACROCCES_H

#include "GPIO_Config.h"

/*========================================= NIXIE TUBES SECTION ===========================================*/

#define NIXIE_LAMP1_ENABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP1_PIN, Bit_SET)
#define NIXIE_LAMP1_DISABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP1_PIN, Bit_RESET)

#define NIXIE_LAMP2_ENABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP2_PIN, Bit_SET)
#define NIXIE_LAMP2_DISABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP2_PIN, Bit_RESET)

#define NIXIE_LAMP3_ENABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP3_PIN, Bit_SET)
#define NIXIE_LAMP3_DISABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP3_PIN, Bit_RESET)

#define NIXIE_LAMP4_ENABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP4_PIN, Bit_SET)
#define NIXIE_LAMP4_DISABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP4_PIN, Bit_RESET)

#define NIXIE_LAMP5_ENABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP5_PIN, Bit_SET)
#define NIXIE_LAMP5_DISABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP5_PIN, Bit_RESET)

#define NIXIE_LAMP6_ENABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP6_PIN, Bit_SET)
#define NIXIE_LAMP6_DISABLE						GPIO_WriteBit(GPIO_LAMPS_PORT, GPIO_LAMP6_PIN, Bit_RESET)
/*=========================================================================================================*/

/*=========================================== DECODER SECTION =============================================*/

#define NIXIE_DECODER_A0_ENABLE				GPIO_WriteBit(GPIO_DECODER_PORT, GPIO_DECODER_A0_PIN, Bit_SET)
#define NIXIE_DECODER_A0_DISABLE			GPIO_WriteBit(GPIO_DECODER_PORT, GPIO_DECODER_A0_PIN, Bit_RESET)

#define NIXIE_DECODER_A1_ENABLE				GPIO_WriteBit(GPIO_DECODER_PORT, GPIO_DECODER_A1_PIN, Bit_SET)
#define NIXIE_DECODER_A1_DISABLE			GPIO_WriteBit(GPIO_DECODER_PORT, GPIO_DECODER_A1_PIN, Bit_RESET)

#define NIXIE_DECODER_A2_ENABLE				GPIO_WriteBit(GPIO_DECODER_PORT, GPIO_DECODER_A2_PIN, Bit_SET)
#define NIXIE_DECODER_A2_DISABLE			GPIO_WriteBit(GPIO_DECODER_PORT, GPIO_DECODER_A2_PIN, Bit_RESET)

#define NIXIE_DECODER_A3_ENABLE				GPIO_WriteBit(GPIO_DECODER_PORT, GPIO_DECODER_A3_PIN, Bit_SET)
#define NIXIE_DECODER_A3_DISABLE			GPIO_WriteBit(GPIO_DECODER_PORT, GPIO_DECODER_A3_PIN, Bit_RESET)
/*=========================================================================================================*/

/*======================================== DECODER DIGITS SECTION =========================================*/

#define NIXIE_DECODER_ZERO						NIXIE_DECODER_A0_DISABLE; \
																			NIXIE_DECODER_A1_DISABLE; \
																			NIXIE_DECODER_A2_DISABLE; \
																			NIXIE_DECODER_A3_DISABLE;
																		
#define NIXIE_DECODER_ONE							NIXIE_DECODER_A0_ENABLE;  \
																			NIXIE_DECODER_A1_DISABLE; \
																			NIXIE_DECODER_A2_DISABLE; \
																			NIXIE_DECODER_A3_DISABLE;
																			
#define NIXIE_DECODER_TWO							NIXIE_DECODER_A0_DISABLE; \
																			NIXIE_DECODER_A1_ENABLE;  \
																			NIXIE_DECODER_A2_DISABLE; \
																			NIXIE_DECODER_A3_DISABLE;
																			
#define NIXIE_DECODER_THREE						NIXIE_DECODER_A0_ENABLE;  \
																			NIXIE_DECODER_A1_ENABLE;  \
																			NIXIE_DECODER_A2_DISABLE; \
																			NIXIE_DECODER_A3_DISABLE;
																			
#define NIXIE_DECODER_FOUR						NIXIE_DECODER_A0_DISABLE; \
																			NIXIE_DECODER_A1_DISABLE; \
																			NIXIE_DECODER_A2_ENABLE;  \
																			NIXIE_DECODER_A3_DISABLE;				

#define NIXIE_DECODER_FIVE						NIXIE_DECODER_A0_ENABLE;  \
																			NIXIE_DECODER_A1_DISABLE; \
																			NIXIE_DECODER_A2_ENABLE;  \
																			NIXIE_DECODER_A3_DISABLE;
																			
#define NIXIE_DECODER_SIX							NIXIE_DECODER_A0_DISABLE; \
																			NIXIE_DECODER_A1_ENABLE;  \
																			NIXIE_DECODER_A2_ENABLE;  \
																			NIXIE_DECODER_A3_DISABLE;		

#define NIXIE_DECODER_SEVEN						NIXIE_DECODER_A0_ENABLE;  \
																			NIXIE_DECODER_A1_ENABLE;  \
																			NIXIE_DECODER_A2_ENABLE;  \
																			NIXIE_DECODER_A3_DISABLE;
																			
#define NIXIE_DECODER_EIGHT						NIXIE_DECODER_A0_DISABLE; \
																			NIXIE_DECODER_A1_DISABLE; \
																			NIXIE_DECODER_A2_DISABLE; \
																			NIXIE_DECODER_A3_ENABLE;	

#define NIXIE_DECODER_NINE						NIXIE_DECODER_A0_ENABLE;  \
																			NIXIE_DECODER_A1_DISABLE; \
																			NIXIE_DECODER_A2_DISABLE; \
																			NIXIE_DECODER_A3_ENABLE;
/*=========================================================================================================*/

/*===================================== NIXIE ONE LAMP VALUE SECTION ======================================*/

#define NIXIE_ONLY_1ST_LAMP_ON				NIXIE_LAMP1_ENABLE; \
																			NIXIE_LAMP2_DISABLE;\
																			NIXIE_LAMP3_DISABLE;\
																			NIXIE_LAMP4_DISABLE;\
																			NIXIE_LAMP5_DISABLE;\
																			NIXIE_LAMP6_DISABLE;

#define NIXIE_ONLY_2ND_LAMP_ON				NIXIE_LAMP1_DISABLE;\
																			NIXIE_LAMP2_ENABLE; \
																			NIXIE_LAMP3_DISABLE;\
																			NIXIE_LAMP4_DISABLE;\
																			NIXIE_LAMP5_DISABLE;\
																			NIXIE_LAMP6_DISABLE;

#define NIXIE_ONLY_3RD_LAMP_ON				NIXIE_LAMP1_DISABLE;\
																			NIXIE_LAMP2_DISABLE;\
																			NIXIE_LAMP3_ENABLE; \
																			NIXIE_LAMP4_DISABLE;\
																			NIXIE_LAMP5_DISABLE;\
																			NIXIE_LAMP6_DISABLE;
																			
#define NIXIE_ONLY_4TH_LAMP_ON				NIXIE_LAMP1_DISABLE;\
																			NIXIE_LAMP2_DISABLE;\
																			NIXIE_LAMP3_DISABLE;\
																			NIXIE_LAMP4_ENABLE; \
																			NIXIE_LAMP5_DISABLE;\
																			NIXIE_LAMP6_DISABLE;
																			
#define NIXIE_ONLY_5TH_LAMP_ON				NIXIE_LAMP1_DISABLE;\
																			NIXIE_LAMP2_DISABLE;\
																			NIXIE_LAMP3_DISABLE;\
																			NIXIE_LAMP4_DISABLE;\
																			NIXIE_LAMP5_ENABLE; \
																			NIXIE_LAMP6_DISABLE;
																			
#define NIXIE_ONLY_6TH_LAMP_ON				NIXIE_LAMP1_DISABLE;\
																			NIXIE_LAMP2_DISABLE;\
																			NIXIE_LAMP3_DISABLE;\
																			NIXIE_LAMP4_DISABLE;\
																			NIXIE_LAMP5_DISABLE;\
																			NIXIE_LAMP6_ENABLE;
/*=========================================================================================================*/

#endif  // DYNAMICINDICATION_H
