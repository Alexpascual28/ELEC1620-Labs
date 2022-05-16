#include "ModeA.h"

void mode_A() {
    
    lcd.clear();
    lcd.printString("Mode A",0,0);
    lcd.refresh();
    wait_ms(250);  // small delay to prevent previous press being detected again

    while (button_a.read() == 0) {
        
        // code goes in here - this acts like the main while(1) loop
        

    }

}