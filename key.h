#ifndef __KEY_H__
#define __KEY_H__

#define KEY1_PIN P3_1
#define KEY2_PIN P3_0
#define KEY3_PIN P3_2
#define KEY4_PIN P3_3

typedef enum {
    KEY_STATE_IDLE,
    KEY_STATE_DEBOUNCE,
    KEY_STATE_PRESS,
    KEY_STATE_LONG_PRESS
} KeyState;

unsigned char Key(void);

#endif