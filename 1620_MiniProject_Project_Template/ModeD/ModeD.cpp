#include "ModeD.h"

void mode_D() {
    
    lcd.clear();
    lcd.printString("Mode D",0,0);
    lcd.refresh();
    wait_ms(250);

    while (button_d.read() == 0) {
        
        // code goes in here - this acts like the main while(1) loop


    }
    
}