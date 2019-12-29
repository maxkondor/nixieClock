#include "DynamicIndication.h"
#include "DynamicIndicationMacrocces.h"


void ShowDigit(uint8_t *digit)
{
	switch(*digit)
	{
		case 0:
			NIXIE_DECODER_ZERO;
		break;
		
		case 1:
			NIXIE_DECODER_ONE;
		break;
		
		case 2:
			NIXIE_DECODER_TWO;
		break;
		
		case 3:
			NIXIE_DECODER_THREE;
		break;
		
		case 4:
			NIXIE_DECODER_FOUR;
		break;
		
		case 5:
			NIXIE_DECODER_FIVE;
		break;
		
		case 6:
			NIXIE_DECODER_SIX;
		break;
		
		case 7:
			NIXIE_DECODER_SEVEN;
		break;
		
		case 8:
			NIXIE_DECODER_EIGHT;
		break;
		
		case 9:
			NIXIE_DECODER_NINE;
		break;
	}
}

void DynamicShow( uint8_t *nixieArr)
{
	
}




