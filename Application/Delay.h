#ifndef DELAY_H
#define DELAY_H

#include <stdbool.h>

#include "stm32f1xx_hal.h"

bool Delay_SetBlink(uint16_t delayVal);
bool Delay_GetTickVal(void);
void Delay_ResetCounter(void);
bool Delay_WaitMs(uint16_t* staticCounter);
uint16_t Delay_GetPressedCounter(void);

#endif // DELAY_H
