#include "mbed.h"

Serial pc(USBTX,USBRX);

DigitalOut red_led(p24);
DigitalOut green_led(p23);
DigitalOut blue_led(p22);

int main(){
    
    //Turn OFF LEDs
    red_led.write(1);
    green_led.write(1);
    blue_led.write(1);
    
    while(1) {

        // readable tells us if a character is waiting to be read
        if (pc.readable()) {
            // if one is there, then read in using getc
            char c = pc.getc();    
            
            //Red LED
            if (c == 'R') {
                red_led.write(0);
            } else if (c == 'r'){
                red_led.write(1);
            }
            
            //Green LED
            if (c == 'G') {
                green_led.write(0);
            } else if (c == 'g'){
                green_led.write(1);
            }
            
            //Blue LED
            if (c == 'B') {
                blue_led.write(0);
            } else if (c == 'b'){
                blue_led.write(1);
            }
        }
    }
}
