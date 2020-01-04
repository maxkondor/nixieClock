#ifndef DS3231_H
#define DS3231_H

#include "I2C_Config.h"

typedef struct{
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t date;
	uint8_t month;
	uint8_t year;
	
}ds3231_str;

void DS3231_ReadData(ds3231_str* timeStr);
void DS3231_WriteData(ds3231_str* timeStr);


#endif // DS3231_H
