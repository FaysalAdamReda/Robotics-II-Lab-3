#include "Led.h"
#include "Button.h"


const int buttonPin = 2;
const int debounceDelay = 50;
//Button button(buttonPin, debounceDelay);


Led led1(3); // create an instance of Led connected to pin 3
Led led2(4); // create an instance of Led connected to pin 4
Led led3(5); // create an instance of Led connected to pin 5
Led led4(6); // create an instance of Led connected to pin 6

Button button(2, 50); // create an instance of Button connected to pin 2 with a debounce delay of 50 ms

int buttonResult;

void setup() {
  Serial.begin(9600);
  led1.init(); // initialize the LED pins as outputs
  led2.init();
  led3.init();
  led4.init();

//  button.begin(); // initialize the button
}

void loop() {
  buttonResult = button.howManyPressed();
  Serial.println(buttonResult);

switch(buttonResult){
case 1:
led1.on();
led2.off();
led3.off();
led4.off();
break;

case 2:
led1.off();
led2.on();
led3.off();
led4.off();
break;

case 3:
led1.off();
led2.off();
led3.on();
led4.off();
break;

case 4:
led1.off();
led2.off();
led3.off();
led4.on();
button.howManyReset();
break;

}
}
