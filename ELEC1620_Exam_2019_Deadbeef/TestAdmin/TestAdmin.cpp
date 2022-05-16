#include "TestAdmin.h"

DigitalIn* TestAdmin::_skipButton = new DigitalIn(p26);
const char* TestAdmin::_str = "";
N5110* TestAdmin::_lcd;
StreamOut* TestAdmin::_streamOut;
bool TestAdmin::printEnabled = false;

void TestAdmin::setTaskName(const char *s, N5110 *lcd, StreamOut *streamout){
  TestAdmin::_str = s;
  TestAdmin::_lcd = lcd;
  TestAdmin::_streamOut = streamout;
}

bool TestAdmin::testRunning(){
  #ifndef DISABLE_WAIT
  // wait(0.2);
  #endif
  if(printEnabled){
    _streamOut->lock();
    _lcd->clear();
    _lcd->printString(_str, 24, 1);
    _lcd->printString("Cycle between", 3, 3);
    _lcd->printString("   tasks by", 0, 4);
    _lcd->printString("  pressing D", 0, 5);
    _lcd->refresh();
    _streamOut->unlock();
  }

  return !*_skipButton;
}

