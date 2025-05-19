#include <REGX52.H>
#include "delay.h"
#include "I2C.h"
#define EEPROM_ADDRESS		0xA0

void EEPROM_WriteByte(unsigned char WordAddress,Data)
{
	I2C_Start();
	I2C_SendByte(EEPROM_ADDRESS);
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_SendByte(Data);
	I2C_ReceiveAck();
	I2C_Stop();
}

unsigned char EEPROM_ReadByte(unsigned char WordAddress)
{
	unsigned char Data;
	I2C_Start();
	I2C_SendByte(EEPROM_ADDRESS);
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_Start();
	I2C_SendByte(EEPROM_ADDRESS|0x01);
	I2C_ReceiveAck();
	Data=I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();
	return Data;
}
void EEPROM_ReadArray(unsigned char addr, int *dat, unsigned char len)
{
    unsigned char i;
    for(i = 0; i < len; i++)
    {
        unsigned char high = EEPROM_ReadByte(addr + i*2);
        unsigned char low = EEPROM_ReadByte(addr + i*2 + 1);
        dat[i] = (high << 8) | low;
        Delay(5);
    }
}

void EEPROM_WriteArray(unsigned char addr, int *dat, unsigned char len)
{
    unsigned char i;
    for(i = 0; i < len; i++)
    {
        unsigned char high = (dat[i] >> 8) & 0xFF;
        unsigned char low = dat[i] & 0xFF;
        EEPROM_WriteByte(addr + i*2, high);
        Delay(5); 
        EEPROM_WriteByte(addr + i*2 + 1, low);
        Delay(5);
    }
}