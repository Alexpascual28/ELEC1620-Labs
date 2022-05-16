#ifndef EXAM_H_
#define EXAM_H_

#include "mbed.h"
#include "ShiftReg.h"
#include "N5110.h"
#include "TestAdmin.h"

void Task1(TestAdmin &tester, PwmOut &b_led, DigitalIn &button_b);

void Task2(TestAdmin &tester, PwmOut &r_led, PwmOut &g_led, AnalogIn &tmp36);

void Task3(TestAdmin &tester, AnalogIn &ldr);

void Task4(TestAdmin &tester, PwmOut &r_led, PwmOut &g_led, PwmOut &b_led, DigitalIn &button_a, DigitalIn &button_b);

void Task5(TestAdmin &tester, BusOut &leds);

void Task6(TestAdmin &tester, BusOut &leds, AnalogIn &joy_v);

void Task7(TestAdmin &tester, ShiftReg &shift, DigitalIn &button_a, DigitalIn &button_b, DigitalIn &button_c);

void Task8(TestAdmin &tester, ShiftReg &shift, DigitalIn &button_a, DigitalIn &button_b);

#endif
