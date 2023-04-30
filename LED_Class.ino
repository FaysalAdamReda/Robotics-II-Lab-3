#include "Led.h"
Led no(13);


void setup() {
  // put your setup code here, to run once:
no.init();
}

void loop() {
  // put your main code here, to run repeatedly:
no.on();
delay(1000);
no.off();
delay(200);
}
