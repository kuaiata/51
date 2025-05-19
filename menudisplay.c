#include "oled.h"
//≤Àµ•œ‘ æ

void menudisplay(int menu1_flag) {
    switch (menu1_flag) {
    case 1: {
        OLED_ShowString(0, 0, "data1");
        OLED_ShowString(0, 2, "data2");
        OLED_ShowString(0, 4, "data3");
        OLED_ShowString(0, 6, "data4");
        OLED_ShowString(90, 0, "<-");
        OLED_ShowString(90, 2, "  ");
        OLED_ShowString(90, 4, "  ");
        OLED_ShowString(90, 6, "  ");
    } break;
    case 2: {
        OLED_ShowString(0, 0, "data1");
        OLED_ShowString(0, 2, "data2");
        OLED_ShowString(0, 4, "data3");
        OLED_ShowString(0, 6, "data4");
        OLED_ShowString(90, 0, "  ");
        OLED_ShowString(90, 2, "<-");
        OLED_ShowString(90, 4, "  ");
        OLED_ShowString(90, 6, "  ");
    } break;
    case 3: {
        OLED_ShowString(0, 0, "data1");
        OLED_ShowString(0, 2, "data2");
        OLED_ShowString(0, 4, "data3");
        OLED_ShowString(0, 6, "data4");
        OLED_ShowString(90, 0, "  ");
        OLED_ShowString(90, 2, "  ");
        OLED_ShowString(90, 4, "<-");
        OLED_ShowString(90, 6, "  ");
    } break;
    case 4: {
        OLED_ShowString(0, 0, "data1");
        OLED_ShowString(0, 2, "data2");
        OLED_ShowString(0, 4, "data3");
        OLED_ShowString(0, 6, "data4");
        OLED_ShowString(90, 0, "  ");
        OLED_ShowString(90, 2, "  ");
        OLED_ShowString(90, 4, "  ");
        OLED_ShowString(90, 6, "<-");
    } break;
    case 5: {
        OLED_ShowString(0, 0, "data5");
        OLED_ShowString(0, 2, "data6");
        OLED_ShowString(0, 4, "data7");
        OLED_ShowString(0, 6, "     ");
        OLED_ShowString(90, 0, "<-");
        OLED_ShowString(90, 2, "  ");
        OLED_ShowString(90, 4, "  ");
        OLED_ShowString(90, 6, "  ");
    } break;
    case 6: {
        OLED_ShowString(0, 0, "data5");
        OLED_ShowString(0, 2, "data6");
        OLED_ShowString(0, 4, "data7");
        OLED_ShowString(0, 6, "     ");
        OLED_ShowString(90, 0, "  ");
        OLED_ShowString(90, 2, "<-");
        OLED_ShowString(90, 4, "  ");
        OLED_ShowString(90, 6, "  ");
    } break;
		case 7: {
        OLED_ShowString(0, 0, "data5");
        OLED_ShowString(0, 2, "data6");
        OLED_ShowString(0, 4, "data7");
        OLED_ShowString(0, 6, "     ");
        OLED_ShowString(90, 0, "  ");
        OLED_ShowString(90, 2, "  ");
        OLED_ShowString(90, 4, "<-");
        OLED_ShowString(90, 6, "  ");
    } break;
    }
}
