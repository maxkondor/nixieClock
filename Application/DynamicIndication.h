#ifndef DYNAMICINDICATION_H
#define DYNAMICINDICATION_H

#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define DYNAMIC_NUM_OF_LAMPS				6
#define DYNAMIC_ANIMAION_DELAY			10
#define DYNAMIC_LAMP_UNACTIVE				10

typedef enum{
	
	DYNAMIC_ANIMATION_NONE = 0,
	DYNAMIC_ANIMATION_ALL_DIGITS,
	DYNAMIC_ANIMATION_ONE_DIGIT,
	
}dynamicAnimations;


void Dynamic_ParseArr(uint8_t* arr, dynamicAnimations animEnum);
bool Dynamic_TimerDelay(uint16_t value);

#endif  // DYNAMICINDICATION_H
