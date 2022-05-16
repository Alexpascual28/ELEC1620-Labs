#include "ModeC.h"

void mode_C()
{

    lcd.clear();
    lcd.printString("Mode C",0,0);
    lcd.refresh();
    wait_ms(250);  // small delay to prevent previous press being detected again

    while (button_c.read() == 0) {

        // code goes in here - this acts like the main while(1) loop


    }

}