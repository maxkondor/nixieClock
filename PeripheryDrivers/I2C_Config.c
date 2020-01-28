#include "I2C_Config.h"

HAL_StatusTypeDef I2C_ReInit(void);

I2C_HandleTypeDef 										I2C_Handler;

HAL_StatusTypeDef I2C_Config(void)
{
	__HAL_RCC_I2C1_CLK_ENABLE();
	
	I2C_Handler.Instance 								= I2C1;
  I2C_Handler.Init.ClockSpeed 				= 100000;
  I2C_Handler.Init.DutyCycle 					= I2C_DUTYCYCLE_2;
  I2C_Handler.Init.OwnAddress1 				= 0x36;
  I2C_Handler.Init.AddressingMode 		= I2C_ADDRESSINGMODE_7BIT;
  I2C_Handler.Init.DualAddressMode 		= I2C_DUALADDRESS_DISABLE;
  I2C_Handler.Init.OwnAddress2 				= 0;
  I2C_Handler.Init.GeneralCallMode 		= I2C_GENERALCALL_DISABLE;
  I2C_Handler.Init.NoStretchMode 			= I2C_NOSTRETCH_DISABLE;
	
  return HAL_I2C_Init(&I2C_Handler);
}

void I2C_WriteData(uint8_t devAddr, uint8_t addr, uint8_t value)
{
	uint8_t sendData[2];
	
	sendData[0] = addr;
	sendData[1] = value;
	
	if(HAL_I2C_Master_Transmit(&I2C_Handler, devAddr, sendData, 2, 50) != HAL_OK)
		I2C_ReInit();
}

uint8_t I2C_ReadData(uint8_t devAddr, uint8_t addr)
{
	uint8_t data[2];
	
	data[0] = addr;

	HAL_I2C_Master_Transmit(&I2C_Handler, devAddr, &data[0], 1, 50);
	
	if(HAL_I2C_Master_Receive(&I2C_Handler, devAddr, &data[1], 1, 50) != HAL_OK)
		I2C_ReInit();
	
	return data[1];
}

HAL_StatusTypeDef I2C_ReInit(void)
{
	HAL_StatusTypeDef status;
	
	if(HAL_I2C_DeInit(&I2C_Handler) == HAL_OK)
	{
		
		status = I2C_Config();
	}
	
	return status;
}
