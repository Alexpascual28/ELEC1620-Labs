#include "mbed.h"
#include "Tone.h"

//Define Tone object
Tone dac(p18);

//Define pin of potentiometer
AnalogIn pot0(p20);

// Megalovania Tune
const int note_array[] = {
    NOTE_D4, NOTE_D4, NOTE_D5, 0,
    NOTE_A4, 0, 0, NOTE_GS4,
    0, NOTE_G4, 0,  NOTE_F4,
    0, NOTE_D4, NOTE_F4, NOTE_G4,

    NOTE_C4, NOTE_C4, NOTE_D5, 0,
    NOTE_A4, 0, 0, NOTE_GS4,
    0, NOTE_G4, 0, NOTE_F4,
    0, NOTE_D4, NOTE_F4, NOTE_G4,

    NOTE_B3, NOTE_B3, NOTE_D5, 0,
    NOTE_A4, 0, 0, NOTE_GS4,
    0, NOTE_G4, 0, NOTE_F4,
    0, NOTE_D4, NOTE_F4, NOTE_G4,

    NOTE_AS3, NOTE_AS3, NOTE_D5, 0,
    NOTE_A4, 0, 0, NOTE_GS4,
    0, NOTE_G4, 0, NOTE_F4,
    0, NOTE_D4, NOTE_F4, NOTE_G4,
};

// 8 corresponds to 1/8
const int duration_array[] = {
    8,8,8,8,
    8,8,8,8,
    8,8,8,8,
    8,8,8,8,

    8,8,8,8,
    8,8,8,8,
    8,8,8,8,
    8,8,8,8,

    8,8,8,8,
    8,8,8,8,
    8,8,8,8,
    8,8,8,8,

    8,8,8,8,
    8,8,8,8,
    8,8,8,8,
    8,8,8,8,
};

int main()
{
    //Initiate DAC
    dac.init();
    
    //read value from 0 to 1 from potentiometer
    float pot_value = pot0.read();
    
    //convert it to a value between 60 and 180
    float bpm = pot_value*120+60;
    
    int n = sizeof(note_array)/sizeof(int);
    // tell it the number of notes, arrays, BPM and whether to repeat
    dac.play_melody(n,note_array,duration_array,bpm,true);

}
