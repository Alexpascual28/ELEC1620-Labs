#ifndef LIB_TESTADMIN_H_
#define LIB_TESTADMIN_H_

#include "mbed.h"
#include "N5110.h"
#include "StreamOut.h"

class TestAdmin{
public:
  static bool testRunning();
  static void setTaskName(const char *str, N5110 *lcd, StreamOut *streamout);
  static bool printEnabled;

private:
  static DigitalIn *_skipButton;
  static const char *_str;
  static N5110 *_lcd;
  static StreamOut *_streamOut;


};

#endif

