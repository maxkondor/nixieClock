#ifndef DELAY_H
#define DELAY_H

#include <stdbool.h>

#include "stm32f1xx_hal.h"

bool Delay_NoPause(uint16_t delayVal);
bool Delay_GetTickVal(void);
void Delay_ResetCounter(void);

#endif // DELAY_H
