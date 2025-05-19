#ifndef __MENU_H__
#define __MENU_H__

#include "eeprom.h"

#define EEPROM_START_ADDR 0x00

extern int number[7];
extern int menu1_flag;

int menu1(void);
int menu2_data1(void);
int menu2_data2(void);
int menu2_data3(void);
int menu2_data4(void);
int menu2_data5(void);
int menu2_data6(void);
int menu2_data7(void);
#endif