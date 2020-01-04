#include "I2C_Config.h"

void I2C_Config(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
	
	I2C_InitTypeDef 											I2C_Struct;
	I2C_DeInit(I2C1);
	
	I2C_Struct.I2C_ClockSpeed 						= 100000;
	I2C_Struct.I2C_Mode 									= I2C_Mode_I2C;
	I2C_Struct.I2C_DutyCycle      				= I2C_DutyCycle_2;
	I2C_Struct.I2C_OwnAddress1						= 0x07;
	I2C_Struct.I2C_Ack										= I2C_Ack_Enable;
	I2C_Struct.I2C_AcknowledgedAddress 		= I2C_AcknowledgedAddress_7bit;
	
	I2C_Cmd(I2C1, ENABLE);
	I2C_Init(I2C1, &I2C_Struct);
}

void I2C_WriteData(uint8_t devAddr, uint8_t addr, uint8_t value)
{
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	
	I2C_Send7bitAddress(I2C1, devAddr, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	
	I2C_SendData(I2C1, addr);
  while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
	I2C_SendData(I2C1, value);
  while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));	
	
	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));
}

uint8_t I2C_ReadData(uint8_t devAddr, uint8_t addr)
{
	uint8_t data = 0;	
	
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	
	I2C_Send7bitAddress(I2C1, devAddr, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));	
	
	I2C_SendData(I2C1, addr);
  while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
	I2C_GenerateSTART(I2C1, ENABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	
	I2C_Send7bitAddress(I2C1, devAddr, I2C_Direction_Receiver);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));	
	
	I2C_AcknowledgeConfig(I2C1, DISABLE);
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
	
	data = I2C_ReceiveData(I2C1);

	I2C_GenerateSTOP(I2C1, ENABLE);
	while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));
	
	return data;
}
