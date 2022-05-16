#include "mbed.h"

DigitalIn button_A(p29);
DigitalOut red_led(p24);

int main() {
    
     // PCB has external pull-down resistors so turn the internal ones off
    // (default for DigitalIn)
    button_A.mode(PullNone);
    
    red_led.write(1);  // turn red LED off to being with

    
    // buttons read 0 when not pressed, so keep looping while A is 0
    while(button_A == 0) {
        // do nothing, just wait for button press
    }
    
    // once A is pressed (=1) the loop will break and the code will continue
    
    red_led.write(0);  // ...and turn LED on
    
}