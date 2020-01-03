#ifndef DYNAMICINDICATION_H
#define DYNAMICINDICATION_H

#include <string.h>
#include <stdint.h>

#define NUM_OF_LAMPS			6

typedef enum{
	GETVal,
	SETVal
}DynamicCounterState;

void Nixie_ShowArr(uint8_t* arr);

#endif  // DYNAMICINDICATION_H
