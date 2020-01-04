#include "DS3231.h"
#include "DS3231Registers.h"

uint8_t DS3231_ConvertFromBinDec(uint8_t data);
uint8_t DS3231_ConvertToBinDec(uint8_t data);

uint8_t DS3231_GetSeconds(void);
uint8_t DS3231_GetMinutes(void);
uint8_t DS3231_GetHours(void);

uint8_t DS3231_GetDate(void);
uint8_t DS3231_GetMonth(void);
uint8_t DS3231_GetYear(void);

void DS3231_SetSeconds(uint8_t seconds);
void DS3231_SetMinutes(uint8_t minutes);
void DS3231_SetHours(uint8_t hours);

void DS3231_SetDate(uint8_t date);
void DS3231_SetMonth(uint8_t month);
void DS3231_SetYear(uint8_t year);


uint8_t DS3231_ConvertFromBinDec(uint8_t data)
{
	uint8_t retData = 0;
	
	retData = ((data >>4 ) * 10 + (0x0F & data));
	
	return retData;
}

uint8_t DS3231_ConvertToBinDec(uint8_t data)
{
	uint8_t retData = 0;
	
	retData = ((data / 10) << 4) | (data % 10);
	
	return retData;
}

uint8_t DS3231_GetSeconds(void)
{
	uint8_t receivedData = 0;
	
	receivedData = DS3231_ConvertFromBinDec(I2C_ReadData(DS3231_DEV_ADDRESS, DS3231_REG_SECONDS));
	
	return receivedData;
}

uint8_t DS3231_GetMinutes(void)
{
	uint8_t receivedData = 0;
	
	receivedData = DS3231_ConvertFromBinDec(I2C_ReadData(DS3231_DEV_ADDRESS, DS3231_REG_MINUTES));
	
	return receivedData;
}

uint8_t DS3231_GetHours(void)
{
	uint8_t receivedData = 0;
	
	receivedData = DS3231_ConvertFromBinDec(I2C_ReadData(DS3231_DEV_ADDRESS, DS3231_REG_HOURS));
	
	return receivedData;
}

uint8_t DS3231_GetDate(void)
{
	uint8_t receivedData = 0;
	
	receivedData = DS3231_ConvertFromBinDec(I2C_ReadData(DS3231_DEV_ADDRESS, DS3231_REG_DATE));
	
	return receivedData;
}

uint8_t DS3231_GetMonth(void)
{
	uint8_t receivedData = 0;
	
	receivedData = DS3231_ConvertFromBinDec(I2C_ReadData(DS3231_DEV_ADDRESS, DS3231_REG_MONTH));
	
	return receivedData;
}

uint8_t DS3231_GetYear(void)
{
	uint8_t receivedData = 0;
	
	receivedData = DS3231_ConvertFromBinDec(I2C_ReadData(DS3231_DEV_ADDRESS, DS3231_REG_YEAR));
	
	return receivedData;
}

void DS3231_SetSeconds(uint8_t seconds)
{
	I2C_WriteData(DS3231_DEV_ADDRESS, DS3231_REG_SECONDS, DS3231_ConvertToBinDec(seconds));
}

void DS3231_SetMinutes(uint8_t minutes)
{
	I2C_WriteData(DS3231_DEV_ADDRESS, DS3231_REG_MINUTES, DS3231_ConvertToBinDec(minutes));
}

void DS3231_SetHours(uint8_t hours)
{
	I2C_WriteData(DS3231_DEV_ADDRESS, DS3231_REG_HOURS, DS3231_ConvertToBinDec(hours));
}

void DS3231_SetDate(uint8_t date)
{
	I2C_WriteData(DS3231_DEV_ADDRESS, DS3231_REG_DATE, DS3231_ConvertToBinDec(date));
}

void DS3231_SetMonth(uint8_t month)
{
	I2C_WriteData(DS3231_DEV_ADDRESS, DS3231_REG_MONTH, DS3231_ConvertToBinDec(month));
}

void DS3231_SetYear(uint8_t year)
{
	I2C_WriteData(DS3231_DEV_ADDRESS, DS3231_REG_YEAR, DS3231_ConvertToBinDec(year));
}

void DS3231_ReadData(ds3231_str* timeStr)
{
	timeStr -> seconds  	= DS3231_GetSeconds();
	timeStr -> minutes 		= DS3231_GetMinutes();
	timeStr -> hours 			= DS3231_GetHours();
	
	timeStr -> date 			= DS3231_GetDate();
	timeStr -> month 			= DS3231_GetMonth();
	timeStr -> year 			= DS3231_GetYear();
}

void DS3231_WriteData(ds3231_str* timeStr)
{
	DS3231_SetSeconds(timeStr -> seconds);
	DS3231_SetMinutes(timeStr -> minutes);
	DS3231_SetHours(timeStr -> hours);
	
	DS3231_SetDate(timeStr -> date);
	DS3231_SetMonth(timeStr -> month);
	DS3231_SetYear(timeStr -> year);
}	
