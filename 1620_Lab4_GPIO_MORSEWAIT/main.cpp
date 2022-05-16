/* Morse Code

(c) Dr Craig A. Evans, University of Leeds

A dot is 1 time unit
A dash is 3 time units
Space between parts of a letter is 1 unit
Space between letters is 3 units
Space between words is 7 units

*/

#include "mbed.h"

DigitalIn button_A(p29);

DigitalOut red_led(p24);
DigitalOut green_led(p23);
DigitalOut blue_led(p22);

void init_leds();
void dot();
void dash();
void morse_s();
void morse_o();
void alex();

// global variable for unit time in milli-seconds
int g_time_unit_ms = 150;

int main()
{
    init_leds();

    button_A.mode(PullNone);
    
    red_led.write(1);
    
    while(button_A == 0) {
        // do nothing, just wait for button press
    }

        alex();
        wait_ms(7*g_time_unit_ms);  // space between words is 7 units
}

// LEDs are active low and so writing a 1 turns them off
void init_leds()
{
    red_led.write(1);
    green_led.write(1);
    blue_led.write(1);
}

void dot()
{
    red_led.write(0);  // turn LED on
    wait_ms(g_time_unit_ms);   // wait for 1 time unit
    red_led.write(1);  // turn LED off
}

void dash() 
{
    red_led.write(0);  // turn LED on
    wait_ms(3*g_time_unit_ms);   // A dash is 3 time units
    red_led.write(1);  // turn LED off
}

void morse_a() {  // .-
    dot();
    wait_ms(g_time_unit_ms);  // space between parts of a letter is 1 unit
    dash();
}

void morse_l() {  // .-..
    dot();
    wait_ms(g_time_unit_ms);  // space between parts of a letter is 1 unit
    dash();
    wait_ms(g_time_unit_ms);
    dot();
    wait_ms(g_time_unit_ms);
    dot();
}

void morse_e() {  // .
    dot();
}

void morse_x() {  // -..-
    dash();
    wait_ms(g_time_unit_ms);  // space between parts of a letter is 1 unit
    dot();
    wait_ms(g_time_unit_ms);
    dot();
    wait_ms(g_time_unit_ms);
    dash(); 
}

void alex() { // .- .-.. . -..-
    morse_a();
    wait_ms(3*g_time_unit_ms);  // space between letters is 3 units
    morse_l();
    wait_ms(3*g_time_unit_ms);  // space between letters is 3 units
    morse_e();  
    wait_ms(3*g_time_unit_ms);  // space between letters is 3 units
    morse_x();
    wait_ms(3*g_time_unit_ms);      
}