#include "mbed.h"
#include "N5110.h"
#include "Tone.h"

//Defines pin of Button A
DigitalIn button_A(p29);

//DAC object defined
Tone dac(p18);

// JP1 must be in 2/3 position
N5110 lcd(p8,p9,p10,p11,p13,p21);

//----------ANIMATION------------

//Draw character
const int run[12][10] =   {
    { 0,0,0,0,0,1,1,1,0,0 },
    { 0,0,0,0,0,1,1,1,0,0 },
    { 0,0,0,1,1,1,1,0,0,0 },
    { 0,0,1,1,1,1,0,1,0,0 },
    { 0,1,1,0,1,1,0,1,1,1 },
    { 1,0,0,0,1,1,0,0,0,0 },
    { 0,0,0,1,1,1,1,0,0,0 },
    { 0,0,1,1,0,0,1,1,0,0 },
    { 1,1,1,1,0,0,0,1,1,0 },
    { 0,0,0,0,0,0,1,1,0,0 },
    { 0,0,0,0,0,1,1,0,0,0 },
    { 0,0,0,0,1,1,0,0,0,0 },
};

//Draw cloud
const int cloud[12][20] =   {
    { 0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
    { 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0 },
    { 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0 },
    { 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
    { 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
    { 0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1 },
    { 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
    { 0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0 },
    { 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0 },
};

const int jump[] = {3,2,1,-1,-2,-3};

//----------MUSIC------------

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

void animation();
void music();

int main(){
    music();
    animation();
}

void animation(){
    // need to initialise the lcd first, do this once outside of the loop
    lcd.init();
    
    int x_run = 0;  // starting position of character
    int y_run = 40-12; //starting vertical position of character
    
    int x_cloud = 84;  // starting position of cloud

    while(1) {
        // clear the display at the start of the loop
        lcd.clear();

        // print any text
        lcd.printString("Run!",0,0);

        // draw the sprite for the cloud at the correct place
        lcd.drawSprite(x_cloud,6,12,20,(int *)cloud);
        
        // draw the required shapes
        lcd.drawRect(0,40,84,8,FILL_BLACK);
        lcd.drawCircle(70,10,5,FILL_TRANSPARENT);
        
        x_run+=2;  // increment x to move sprite across 2 pixels each loop
        
        x_cloud-=1;  // decrease x to move sprite across 2 pixels each loop
        
        if (x_run>83) {  // if gone off screen then move back to left
            x_run=0;    
        }
        
        if (x_cloud<0-20) {  // if gone off screen then move back to right
            x_cloud=84;    
        }
        
        // draw the sprite for the character at the correct place
        lcd.drawSprite(x_run,y_run,12,10,(int *)run);
        
        lcd.refresh(); // refresh the LCD so the pixels appear
        wait_ms(1000/10);  // this gives a refresh rate of 10 frames per second
        
        
        
        if (button_A.read() == 1) {
            for(int i = 0; i<6; i++){
                // clear the display at the start of the loop
                lcd.clear();
        
                // print any text
                lcd.printString("Run!",0,0);
        
                // draw the sprite for the cloud at the correct place
                lcd.drawSprite(x_cloud,6,12,20,(int *)cloud);
                
                // draw the required shapes
                lcd.drawRect(0,40,84,8,FILL_BLACK);
                lcd.drawCircle(70,10,5,FILL_TRANSPARENT);
                
                x_run+=2;  // increment x to move sprite across 2 pixels each loop
                
                x_cloud-=1;  // decrease x to move sprite across 2 pixels each loop
                
                if (x_run>83) {  // if gone off screen then move back to left
                    x_run=0;    
                }
                
                if (x_cloud<0-20) {  // if gone off screen then move back to right
                    x_cloud=84;    
                }
                
                y_run-=jump[i];
                
                // draw the sprite for the character at the correct place
                lcd.drawSprite(x_run,y_run,12,10,(int *)run);
                
                lcd.refresh(); // refresh the LCD so the pixels appear
                wait_ms(1000/10);  // this gives a refresh rate of 10 frames per second
            }
        }
    }
}

void music(){
    dac.init();
    
    int n = sizeof(note_array)/sizeof(int);
    // tell it the number of notes, arrays, BPM and whether to repeat
    dac.play_melody(n,note_array,duration_array,120.0,true);
}




