#ifndef LIB_STREAMOUT_H_
#define LIB_STREAMOUT_H_

#include <mbed.h>
#include "Message.h"

#define BUFFERSIZE 1024

class StreamOut{
public:
  //StreamOut(PinName clk, PinName data, PinName latch);
  StreamOut();
  ~StreamOut();
  void init();
  void lock();
  void unlock();
  void writeMessage(char code, unsigned int data);
  void sendMessages();

private:
  static DigitalOut *_clk;
  static DigitalOut *_latch;
  static DigitalOut *_data;

  static int _index;
  static int _locked;
  static Message _buffer[BUFFERSIZE];

  void sendMessage(Message msg);

};

#endif

