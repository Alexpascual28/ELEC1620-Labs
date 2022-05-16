#include <mbed.h>

#include "ShiftReg.h"
#include "N5110.h"

#include "StreamOut.h"

#include "exam.h"

// #define IGNORE_SETUP


AnalogIn ldr(p15);

AnalogIn tmp36(p16);

AnalogIn pot_0(p20);
AnalogIn pot_1(p19);
AnalogIn pot_2(p17);

PwmOut r_led(p24);
PwmOut g_led(p23);
PwmOut b_led(p22);

DigitalIn button_a(p29);
DigitalIn button_b(p28);
DigitalIn button_c(p27);
DigitalIn button_d(p26);

N5110 lcd(p8,p9,p10,p11,p13,p21);

BusOut leds(LED4,LED3,LED2,LED1);

ShiftReg shift;

StreamOut streamOut;

TestAdmin testAdmin;

void init(){
  //streamOut.lock();
  lcd.init();
  r_led.period_ms(10);
  g_led.period_ms(10);
  b_led.period_ms(10);
  //streamOut.unlock();
}

void reset(){
  r_led = 1;
  g_led = 1;
  b_led = 1;
  shift.write(0x00);
  // streamOut.lock();
  lcd.clear();
  lcd.refresh();
  // streamOut.unlock();
  leds = 0x0;
}

void waitRelease(){
  streamOut.writeMessage(0xf, 0xFD);
  streamOut.sendMessages();
  streamOut.lock();
  while(!testAdmin.testRunning()){
  }
  // lcd.clear();
  // lcd.refresh();
  streamOut.unlock();
}

int main() {
  printf("Start\n");
  streamOut.unlock();
  streamOut.writeMessage(0xf, 0x0);
  streamOut.sendMessages();

  init();
  reset();
  lcd.setBrightness(1.0f);

  #ifndef IGNORE_SETUP

  while(testAdmin.testRunning()){
    // streamOut.lock();
    lcd.clear();
    lcd.printString("  Adjust the", 0, 0);
    lcd.printString("contrast with", 3, 1);
    lcd.printString("    Pot 2", 0, 2);
    lcd.printString("Cycle between", 3, 3);
    lcd.printString("   tasks by", 0, 4);
    lcd.printString("  pressing D", 0, 5);
    lcd.setContrast(0.5 + (pot_2 - 0.5) * 0.4);
    lcd.refresh();
    // while(!button_a){}
    // while(button_a){}

    // streamOut.unlock();
  }
  reset();
  #endif
  testAdmin.printEnabled = true;
  while(1){
    #ifndef IGNORE_TASK_1
    printf("Task 1\n");
    testAdmin.setTaskName("Task 1", &lcd, &streamOut);
    waitRelease();
    streamOut.writeMessage(0xf, 0x1);
    streamOut.sendMessages();
    Task1(testAdmin, b_led, button_b);
    reset();
    #endif
    #ifndef IGNORE_TASK_2
    printf("Task 2\n");
    testAdmin.setTaskName("Task 2", &lcd, &streamOut);
    waitRelease();
    streamOut.writeMessage(0xf, 0x2);
    streamOut.sendMessages();
    Task2(testAdmin, r_led, g_led, tmp36);
    reset();
    #endif
    #ifndef IGNORE_TASK_3
    printf("Task 3\n");
    testAdmin.setTaskName("Task 3", &lcd, &streamOut);
    waitRelease();
    streamOut.writeMessage(0xf, 0x3);
    streamOut.sendMessages();
    Task3(testAdmin, ldr);
    reset();
    #endif
    #ifndef IGNORE_TASK_4
    printf("Task 4\n");
    testAdmin.setTaskName("Task 4", &lcd, &streamOut);
    waitRelease();
    streamOut.writeMessage(0xf, 0x4);
    streamOut.sendMessages();
    Task4(testAdmin, r_led, g_led, b_led, button_a, button_b);
    reset();
    #endif
    #ifndef IGNORE_TASK_5
    printf("Task 5\n");
    testAdmin.setTaskName("Task 5", &lcd, &streamOut);
    waitRelease();
    streamOut.writeMessage(0xf, 0x5);
    streamOut.sendMessages();
    Task5(testAdmin, leds);
    reset();
    #endif
    #ifndef IGNORE_TASK_6
    printf("Task 6\n");
    testAdmin.setTaskName("Task 6", &lcd, &streamOut);
    waitRelease();
    streamOut.writeMessage(0xf, 0x6);
    streamOut.sendMessages();
    Task6(testAdmin, leds, pot_0);
    reset();
    #endif
    #ifndef IGNORE_TASK_7
    printf("Task 7\n");
    testAdmin.setTaskName("Task 7", &lcd, &streamOut);
    waitRelease();
    streamOut.writeMessage(0xf, 0x7);
    streamOut.sendMessages();
    Task7(testAdmin, shift, button_a, button_b, button_c);
    reset();
    #endif
    #ifndef IGNORE_TASK_8
    printf("Task 8\n");
    testAdmin.setTaskName("Task 8", &lcd, &streamOut);
    waitRelease();
    streamOut.writeMessage(0xf, 0x8);
    streamOut.sendMessages();
    Task8(testAdmin, shift, button_a, button_b);
    reset();
    #endif
  }
}
