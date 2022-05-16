#include "Message.h"

Message::Message(char code, unsigned int data):
  _code(code),
  _data(data)
{

}

Message::Message():
  _code(0x0F),
  _data(0x00)
{

}

Message::~Message(){}

void Message::set(char code, unsigned int data){
  _code = code;
  _data = data;
}

char Message::get_code(){
  return _code;
}

unsigned int Message::get_data(){
  return _data;
}

