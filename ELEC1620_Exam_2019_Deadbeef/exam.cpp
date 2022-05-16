#include "exam.h"

// Task 1
// Hold the B button to turn the Blue LED on, release to turn off.
// (3 marks)
void Task1(TestAdmin &tester, PwmOut &b_led, DigitalIn &button_b){
    // Code here that executed at the start of the task
    b_led.write(1);
  
    while(tester.testRunning()){    // Run until button D is pressed
        // Code here that executed continously during the task
    
    if(button_b.read() == 1){
        b_led.write(0);
    } else {
        b_led.write(1);
    }
    }
}

// Task 2
// Green LED is lit if the temperature sensor value is greater or equal to 25 °C and the red LED is lit if the temperature is below 25 °C.
// (3 marks)
void Task2(TestAdmin &tester, PwmOut &r_led, PwmOut &g_led, AnalogIn &tmp36){
    // Code here that executed at the start of the task
  
    r_led.write(1);
    g_led.write(1);

    while(tester.testRunning()){    // Run until button D is pressed
        // Code here that executed continously during the task
    
        // read in the ADC value and convert to voltage
        float voltage = 3.3f * tmp36.read();
        
        // convert voltage to temperature in Celsius
        float temperature = 100.0f*voltage - 50.0f;
        
        if(temperature >= 25) {
            g_led.write(0);
        } else if (temperature < 25) {
            r_led.write(0);
        } else {
            r_led.write(1);
            g_led.write(1);
        }
    }
}

// Task 3
// Print the character “D” over serial if the LDR is covered (i.e. dark) and “L” if uncovered (i.e. light).
// Ensure you use upper-case characters and a newline character to terminate the string.
// (3 marks)
void Task3(TestAdmin &tester, AnalogIn &ldr){
    // Code here that executed at the start of the task
  
    Serial pc(USBTX,USBRX);
    
    while(tester.testRunning()){    // Run until button D is pressed
        // Code here that executed continously during the task
    
    if(ldr.read()<0.25){
    pc.printf("D");
    } else if(ldr.read()>=0.25){
    pc.printf("L");
    }
    
    }
}

// Task 4
// Implement the following logic table using the buttons and LEDs.
// Button A Pressed | Button B Pressed | LED Output
//        0         |        0         |   Off
//        0         |        1         |   Red
//        1         |        0         |  Green
//        1         |        1         |  Blue
// (4 marks)
void Task4(TestAdmin &tester, PwmOut &r_led, PwmOut &g_led, PwmOut &b_led, DigitalIn &button_a, DigitalIn &button_b){
    // Code here that executed at the start of the task
            
    r_led.write(1);
    g_led.write(1);
    b_led.write(1);

    while(tester.testRunning()){    // Run until button D is pressed
        // Code here that executed continously during the task
    
    if(button_a.read() == 0){
        if(button_b.read() == 0){
                r_led.write(1);
                g_led.write(1);
                b_led.write(1);
        } 
        else if(button_b.read() == 1){
                r_led.write(0);
        }
    }
    else if(button_a.read() == 1){
        if(button_b.read() == 0){
                g_led.write(0);
        } 
        else if(button_b.read() == 1){
                b_led.write(0);
        }
    }
    }
}

// Task 5
// Loop through the following pattern on the on-board LEDs with a 0.25 second delay between each one.
//  LED1 | LED2 | LED3 | LED4
// XXXXXX|      |XXXXXX|     
//       |XXXXXX|      |XXXXXX
// XXXXXX|      |      |XXXXXX
//       |XXXXXX|XXXXXX|      
// (4 marks)
void Task5(TestAdmin &tester, BusOut &leds){
    // Code here that executed at the start of the task
    leds.write(7);
    while(tester.testRunning()){    // Run until button D is pressed
        // Code here that executed continously during the task
    leds.write(1010);
    wait_ms(250);
    leds.write(0101);
    wait_ms(250);    
    leds.write(0110);
    wait_ms(250);    
    leds.write(1001);
    }
}

// Task 6
// The range of vertical movement of the joystick should be split into three distinct positions – up, down and centred.
// The following pattern should be displayed on the LEDs depending on the joystick position. 
//       | LED1 | LED2 | LED3 | LED4
//  UP   |      |      |XXXXXX|XXXXXX
//CENTRED|      |XXXXXX|XXXXXX|      
// DOWN  |XXXXXX|XXXXXX|      |      
// (3 marks)
void Task6(TestAdmin &tester, BusOut &leds, AnalogIn &joy_v){
    // Code here that executed at the start of the task
    
    leds.write(7);
    
    while(tester.testRunning()){    // Run until button D is pressed
        // Code here that executed continously during the task
    
    if(joy_v<=0.33){
        leds.write(1100);
    } else if (joy_v<=0.66) {
        leds.write(1001);
    } else if (joy_v>0.66) {
        leds.write(0011);
    }
    }
}


// Task 7
// The following patterns should appear on the 7-segment display when the corresponding buttons are pressed.
// When no button is pressed, the display should be off.
//     ____      |               |    ____
//    |    |     |   |           |   |
//    |____|     |   |____       |   |
//    |    |     |   |    |      |   |
//    |    |     |   |____|      |   |____
//   Button A    |  Button B     |  Button C
// (4 marks)
void Task7(TestAdmin &tester, ShiftReg &shift, DigitalIn &button_a, DigitalIn &button_b, DigitalIn &button_c){
    // Code here that executed at the start of the task

    while(tester.testRunning()){    // Run until button D is pressed
        // Code here that executed continously during the task
        shift.write(0x00);
    if(button_a.read()==1){
    shift.write(0x77);
    } else if(button_a.read()==1){
        shift.write(0x7C);
        } else if(button_a.read()==1){
            shift.write(0x39);
            }
    }
}

// Task 8
// The numeric digit ‘0’ should be displayed on the 7-segment display. 
// Pressing button A causes the number displayed to increase and pressing button B causes the number displayed to decrease.
// The numbers should wrap around at 0 and 9 i.e. pressing button A will output the sequence …,8, 9, 0, 1, 2,… and pressing button B will output the sequence …,2,1, 0, 9, 8,....
// (6 marks)
void Task8(TestAdmin &tester, ShiftReg &shift, DigitalIn &button_a, DigitalIn &button_b){
    // Code here that executed at the start of the task
  
    while(tester.testRunning()){    // Run until button D is pressed
        // Code here that executed continously during the task
    
    }
}

