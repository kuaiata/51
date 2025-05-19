#include "REG51.h"
#include "oled.h"
#include "delay.h"
#include "key.h"
#include "menu.h"
int menu2;
int main(void) {    
    OLED_Init();
    while(1) {    
        menu2 = menu1();
        if(menu2==1) menu2_data1();       
        if(menu2==2) menu2_data2();         
        if(menu2==3) menu2_data3();
        if(menu2==4) menu2_data4();       
        if(menu2==5) menu2_data5();         
        if(menu2==6) menu2_data6();  
				if(menu2==7) menu2_data7();  			
    }        
}