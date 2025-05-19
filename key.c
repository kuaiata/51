#include "key.h"
#include "delay.h"
#include <REGX52.H>

unsigned char Key(void) {
    static KeyState keyState = KEY_STATE_IDLE;//初始状态
    static unsigned char lastKey = 0;//上次按键值
    static unsigned int pressTime = 0;//按键按下时间
    unsigned char keyNumber = 0;//当前按键值
		//检测按键
    if(KEY1_PIN == 0) keyNumber = 1;
    else if(KEY2_PIN == 0) keyNumber = 2;
    else if(KEY3_PIN == 0) keyNumber = 3;
    else if(KEY4_PIN == 0) keyNumber = 4;
    
    switch(keyState) {
        case KEY_STATE_IDLE://空闲状态
            if(keyNumber != 0) {
                lastKey = keyNumber;//记录
                keyState = KEY_STATE_DEBOUNCE;//进入消抖状态
            }
            break;
            
        case KEY_STATE_DEBOUNCE://消抖状态
            if((lastKey == 1 && KEY1_PIN == 0) ||
               (lastKey == 2 && KEY2_PIN == 0) ||
               (lastKey == 3 && KEY3_PIN == 0) ||
               (lastKey == 4 && KEY4_PIN == 0)) {
                keyState = KEY_STATE_PRESS;//进入按下状态
                pressTime = 0;//重置按下时间
            } else {
                keyState = KEY_STATE_IDLE;//返回空闲状态
            }
            break;
            
        case KEY_STATE_PRESS://按下状态
            pressTime++;
            if(keyNumber == 0) {
                keyState = KEY_STATE_IDLE;
                return lastKey;
            }
            if(pressTime > 20) {//长按判定
                keyState = KEY_STATE_LONG_PRESS;
                return lastKey | 0x80;//最高位置1，表示长按
            }
            break;
            
        case KEY_STATE_LONG_PRESS:
            if(keyNumber == 0) {
                keyState = KEY_STATE_IDLE;
            } else {
                pressTime++;
                if(pressTime % 5 == 0) {//每5次触发一次
                    return lastKey | 0x80;
                }
            }
            break;
    }
    return 0;
}