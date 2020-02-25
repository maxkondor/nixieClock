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
	
}ds3231_struct;

typedef struct{
	
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	
}ds3231_timeStruct;

typedef struct{
	
	uint8_t date;
	uint8_t month;
	uint8_t year;
	
}ds3231_dateStruct;

void DS3231_ReadData(ds3231_struct* dataStr);
void DS3231_ReadTime(ds3231_timeStruct* timeStr);
void DS3231_ReadDate(ds3231_dateStruct* dateStr);

void DS3231_WriteData(ds3231_struct* dataStr);
void DS3231_WriteTime(ds3231_timeStruct* timeStr);
void DS3231_WriteDate(ds3231_dateStruct* dateStr);

#endif // DS3231_H
