#ifndef __EEPROM_H__
#define __EEPROM_H__

void EEPROM_WriteByte(unsigned char WordAddress,Data);
unsigned char EEPROM_ReadByte(unsigned char WordAddress);
void EEPROM_ReadArray(unsigned char addr,int *dat,unsigned char len);
void EEPROM_WriteArray(unsigned char addr,int *dat,unsigned char len);

#endif
