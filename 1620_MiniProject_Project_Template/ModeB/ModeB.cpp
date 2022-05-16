#include "ModeB.h"

void mode_B()
{

    lcd.clear();
    lcd.printString("Mode B",0,0);
    lcd.refresh();
    wait_ms(250);

    while (button_b.read() == 0) {

        // code goes in here - this acts like the main while(1) loop


    }

}