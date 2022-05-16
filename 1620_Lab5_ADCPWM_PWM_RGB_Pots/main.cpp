#include "mbed.h"

PwmOut red_led(p24);
PwmOut green_led(p23);
PwmOut blue_led(p22);

AnalogIn pot0(p20);
AnalogIn pot1(p19);
AnalogIn pot2(p17);

int main() {
    
    float frequency = 100.0f;  // 100 Hz
    red_led.period(1.0f/frequency);  // set the period of the waveform
    // all PWM channels share the same period so only need to set for one
    
    while(1){
        
        float pot0_val = pot0.read();  // returns a float in the range 0.0 to 1.0
        float pot1_val = pot1.read();
        float pot2_val = pot2.read();            
        
        red_led.write(pot0_val);    // fade R LED with pot0
        green_led.write(pot1_val);  // fade G LED with pot1
        blue_led.write(pot2_val);   // fade B LED with pot2

        wait(0.2);
    }
}
