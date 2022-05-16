#include "StreamOut.h"
//PinName clk, PinName data, PinName latch

int StreamOut::_index = 0;
int StreamOut::_locked = 0;
Message StreamOut::_buffer[BUFFERSIZE];
DigitalOut* StreamOut::_clk = new DigitalOut(p6);
DigitalOut* StreamOut::_latch = new DigitalOut(p25);
DigitalOut* StreamOut::_data = new DigitalOut(p14);

StreamOut::StreamOut()
{

}

StreamOut::~StreamOut(){
  delete _clk, _latch, _data;
}

void StreamOut::lock(){
  _locked++;
}

void StreamOut::unlock(){
  _locked--;
  if(_locked < 0){
    _locked = 0;
  }
}

void StreamOut::init(){

}

void StreamOut::writeMessage(char code, unsigned int data){
  if(_index < BUFFERSIZE && _locked == 0){
    // printf("Write message: %x %x\n", code, data);
    // delete _buffer[_index];
    _buffer[_index].set(code, data);
    _index++;
  }
}

void StreamOut::sendMessages(){
  // printf("Send message\n");
  int remove = 0;
  while(remove < _index){
    sendMessage(_buffer[remove]);
    remove++;
  }
  _index = 0;
  //printf("Messages sent\n");
}

void StreamOut::sendMessage(Message msg){
  // printf("Message sent: %x %x\n", msg.get_code(), msg.get_data());
  *_latch = 1;
  // wait_us(30);
  for(int i = 3; i >= 0; i--){
    *_clk = 0;
    wait_us(5);
    *_data = (msg.get_code() & (1 << i)) != 0;
    *_clk = 1;
    wait_us(5);
  }
  for (int i = 31; i >=  0; i--) {
    *_clk = 0;
    wait_us(5);
    *_data = (msg.get_data() & (1 << i)) != 0;
    *_clk = 1;
    wait_us(5);
  }
  *_latch = 0;
  wait_us(10);
}

