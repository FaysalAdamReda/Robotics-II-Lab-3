#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  private:
    int buttonPin;
    int debounceDelay;
    int buttonState;
    int lastButtonState;
    unsigned long lastDebounceTime;
    int thisMany;
    
  public:
    Button(int pin, int delay);
    int update();
    int isPressed();
    int howManyPressed();
    int howManyReset();
};

#endif
