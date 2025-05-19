#include "key.h"
#include "delay.h"
#include <REGX52.H>

unsigned char Key(void) {
    static KeyState keyState = KEY_STATE_IDLE;//��ʼ״̬
    static unsigned char lastKey = 0;//�ϴΰ���ֵ
    static unsigned int pressTime = 0;//��������ʱ��
    unsigned char keyNumber = 0;//��ǰ����ֵ
		//��ⰴ��
    if(KEY1_PIN == 0) keyNumber = 1;
    else if(KEY2_PIN == 0) keyNumber = 2;
    else if(KEY3_PIN == 0) keyNumber = 3;
    else if(KEY4_PIN == 0) keyNumber = 4;
    
    switch(keyState) {
        case KEY_STATE_IDLE://����״̬
            if(keyNumber != 0) {
                lastKey = keyNumber;//��¼
                keyState = KEY_STATE_DEBOUNCE;//��������״̬
            }
            break;
            
        case KEY_STATE_DEBOUNCE://����״̬
            if((lastKey == 1 && KEY1_PIN == 0) ||
               (lastKey == 2 && KEY2_PIN == 0) ||
               (lastKey == 3 && KEY3_PIN == 0) ||
               (lastKey == 4 && KEY4_PIN == 0)) {
                keyState = KEY_STATE_PRESS;//���밴��״̬
                pressTime = 0;//���ð���ʱ��
            } else {
                keyState = KEY_STATE_IDLE;//���ؿ���״̬
            }
            break;
            
        case KEY_STATE_PRESS://����״̬
            pressTime++;
            if(keyNumber == 0) {
                keyState = KEY_STATE_IDLE;
                return lastKey;
            }
            if(pressTime > 20) {//�����ж�
                keyState = KEY_STATE_LONG_PRESS;
                return lastKey | 0x80;//���λ��1����ʾ����
            }
            break;
            
        case KEY_STATE_LONG_PRESS:
            if(keyNumber == 0) {
                keyState = KEY_STATE_IDLE;
            } else {
                pressTime++;
                if(pressTime % 5 == 0) {//ÿ5�δ���һ��
                    return lastKey | 0x80;
                }
            }
            break;
    }
    return 0;
}