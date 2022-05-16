#include "mbed.h"
#include "ShiftReg.h"  // include ShiftReg library

ShiftReg shift;  // create ShiftReg object

int main()
{
    // values for 0 - 9 + a - f in hex
    int seven_seg_array [] = {
        0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,0x77,0x7C,0x39,0x5E,0x79,0x71
    };

    // write 0 to 7-seg to turn it off
    shift.write(0x00);

    while(1) {
        // loop through the array
        for(int i = 0; i < 16; i++) {
            shift.write(seven_seg_array[i]);
            wait(0.5);
        }

    }
}
