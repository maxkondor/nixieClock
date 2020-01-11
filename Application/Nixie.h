#ifndef NIXIE_H
#define NIXIE_H

#include "DS3231.h"
#include "DynamicIndication.h"

#include <stdbool.h>

typedef enum{
	NIXIE_ANIMATE_NONE,
	NIXIE_ANIMATE_ONE_LAMP,
	NIXIE_ANIMATE_ALL_LAMPS
}nixieAnimation;

void Nixie_ShowTime(void);

#endif // NIXIE_H
