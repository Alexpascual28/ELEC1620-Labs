#include "mbed.h"
#include "N5110.h"

// JP1 on board must be in 2-3 position
N5110 lcd(p8,p9,p10,p11,p13,p21);

// these pins are shared by the potentiometers
AnalogIn  joy_v(p20);
AnalogIn  joy_h(p19);

int main() {
    
    lcd.init();  // need to initialise the LCD
    
    while(1) {
        
        // clear the display at the start of every new frame
        lcd.clear();

        // read each of the pins              
        float x = 76.0f-joy_h.read()*76.0f;
        float y = 40.0f-joy_v.read()*40.0f;
        
        // lcd is 84 pixels wide x 48 pixels high
        
        lcd.drawRect(x,y,8,8,FILL_BLACK);
        
        // update the LCD
        lcd.refresh();   

        // small delay between readings
        wait(0.2);
        
    }
}
