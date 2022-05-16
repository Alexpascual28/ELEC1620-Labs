#ifndef LIB_MESSAGE_H_
#define LIB_MESSAGE_H_

#include <mbed.h>

class Message{
public:
  Message(char code, unsigned int data);
  Message();
  ~Message();
  void set(char code, unsigned int data);
  char get_code();
  unsigned int get_data();
private:
  char _code;
  unsigned int _data;
};

#endif

