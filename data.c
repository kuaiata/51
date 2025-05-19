#include "REG51.h"
#include "oled.h"
#include "delay.h"
#include "key.h"
#include "data.h"

int Data(unsigned char num, int step) {
    unsigned char keyNum = 0;  
    OLED_ShowString(0, 0, "data:");
    OLED_ShowNum(48, 0, num, 5, 16);

    while (1) {
        keyNum = Key();//��ȡ����
        if (keyNum == 1) {  //����һ���˵�
            OLED_Clear();
            return num;
        }
        
        if (keyNum == 3 || keyNum == (3 | 0x80)) {  //������ֵ
            num += step;
            OLED_ShowNum(48, 0, num, 5, 16);
            if(keyNum & 0x80) {
                while((keyNum = Key()) == (3 | 0x80)) {
                    num += step;
                    OLED_ShowNum(48, 0, num, 5, 16);
                    Delay(50);
                }
            }
        }
        if (keyNum == 4 || keyNum == (4 | 0x80)) {  //������ֵ
            num -= step;
            OLED_ShowNum(48, 0, num, 5, 16);
            if(keyNum & 0x80) {
                while((keyNum = Key()) == (4 | 0x80)) {
                    num -= step;
                    OLED_ShowNum(48, 0, num, 5, 16);
                    Delay(50);
                }
            }
        }
        Delay(10);
    }
}