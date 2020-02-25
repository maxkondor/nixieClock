#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

#include "stm32f1xx_hal.h"

#define DS3231_I2C_ADDRESS				0xD0

HAL_StatusTypeDef I2C_Config(void);
void I2C_WriteData(uint8_t devAddr, uint8_t addr, uint8_t value);
uint8_t I2C_ReadData(uint8_t devAddr, uint8_t addr);
HAL_StatusTypeDef I2C_ReInit(void);


#endif //I2C_CONFIG_H
