#include "REG51.h"
#include "oled.h"
#include "delay.h"
#include "key.h"
#include "menu.h"
#include "eeprom.h"
#include "data.h"
#include "menudisplay.h"
int number[7] = { 0,0,0,0,0,0,0 };
int menu1_flag = 1;
int step=1;//步长
int menu1() {
    unsigned char keyNum = 0;
    static unsigned char firstRun = 1;//首次运行
    if (firstRun) {//首次运行时读取数据
        EEPROM_ReadArray(EEPROM_START_ADDR, number, 6);
        firstRun = 0;
    }

    while (1) {
        keyNum = Key();
        if (keyNum == 1 || keyNum == (1 | 0x80)) {//向下选择菜单
            menu1_flag++;
            if (menu1_flag == 8) menu1_flag = 1;
            menudisplay(menu1_flag);
            if (keyNum & 0x80) {
                Delay(30);
                while (1) {
                    keyNum = Key();
                    if (keyNum != (1 | 0x80)) break;
                    menu1_flag++;
                    if (menu1_flag == 8) menu1_flag = 1;
                    menudisplay(menu1_flag);
                    Delay(20);
                }
            }
        }

        if (keyNum == 2 || keyNum == (2 | 0x80)) {//向上选择菜单
            menu1_flag--;
            if (menu1_flag == 0) menu1_flag = 7;
            menudisplay(menu1_flag);
            if (keyNum & 0x80) {
                Delay(30);
                while (1) {
                    keyNum = Key();
                    if (keyNum != (2 | 0x80)) break;
                    menu1_flag--;
                    if (menu1_flag == 0) menu1_flag = 7;
                    menudisplay(menu1_flag);
                    Delay(20);
                }
            }
        }
        if (keyNum == 3) {//确认键，进入二级菜单
            OLED_Clear();
            return menu1_flag;
        }
        if (keyNum == 4) {//保存数据
            EEPROM_WriteArray(EEPROM_START_ADDR, number, 6);
            OLED_Clear();
            OLED_ShowCHinese(18, 2, 0); // 保
            OLED_ShowCHinese(36, 2, 1); // 存
            OLED_ShowCHinese(54, 2, 2); // 成
            OLED_ShowCHinese(72, 2, 3); // 功
            Delay(1000);
            OLED_Clear();
        }

        menudisplay(menu1_flag);
    }
}

// 二级菜单
int menu2_data1() { number[0] = Data(number[0], step); return 0; }
int menu2_data2() { number[1] = Data(number[1], step); return 0; }
int menu2_data3() { number[2] = Data(number[2], step); return 0; }
int menu2_data4() { number[3] = Data(number[3], step); return 0; }
int menu2_data5() { number[4] = Data(number[4], step); return 0; }
int menu2_data6() { number[5] = Data(number[5], step); return 0; }
int menu2_data7() { number[6] = Data(number[6], step); return 0; }