#include "Led.h"

Led::Led(int pin){
  _pin=pin;
}
void Led::init(){
  pinMode(_pin,OUTPUT);
}
void Led::on(){
  digitalWrite(_pin,1);
}
void Led::off(){
  digitalWrite(_pin,0);
}
