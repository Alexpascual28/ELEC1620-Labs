#include "mbed.h"
#include "N5110.h"

// JP1 on board must be in 2-3 position
N5110 lcd(p8,p9,p10,p11,p13,p21);

AnalogIn pot0(p20);
AnalogIn pot1(p19);
AnalogIn pot2(p17);

int main() {
    
    lcd.init();  // need to initialise the LCD
    
    while(1) {
        
        // clear the display at the start of every new frame
        lcd.clear();
        
        // lcd is 84 pixels wide x 48 pixels high
        
        //  x, y,  width, height, fill type
        lcd.drawRect(20,10,8,28,FILL_TRANSPARENT);
        lcd.drawRect(38,10,8,28,FILL_TRANSPARENT);
        lcd.drawRect(56,10,8,28,FILL_TRANSPARENT);
        
        float pot0_val = pot0.read(); // returns a float in the range 0.0 to 1.0
        float pot1_val = pot1.read();
        float pot2_val = pot2.read();
        
        int height0 = int(pot0_val*28.0f); // convert to an int in the range 0.0 to 60.0
        int height1 = int(pot1_val*28.0f);
        int height2 = int(pot2_val*28.0f);
        
        // draw a bar of the correct width
        lcd.drawRect(20,38-height0,8,height0,FILL_BLACK);
        lcd.drawRect(38,38-height1,8,height1,FILL_BLACK);
        lcd.drawRect(56,38-height2,8,height2,FILL_BLACK); 
        
        // update the LCD, to print in screen
        lcd.refresh(); 
        
        // small delay between readings
        wait(0.2);
        
    }
}


