#include "Button.h"

Button::Button(int pin, int delayInputted) {
  buttonPin = pin;
  debounceDelay = delayInputted;
  buttonState = HIGH;
  lastButtonState = LOW;
  lastDebounceTime = 0;
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

int Button::isPressed() {  
  int reading = digitalRead(buttonPin);

  if (!lastButtonState && !reading) {
    Serial.println("The button has been pressed!");
    lastButtonState = HIGH;
    return lastButtonState;
  } else if (lastButtonState && reading) {
    lastButtonState = LOW;
    return lastButtonState;
  }
}

int Button::howManyPressed() {  
  int reading = digitalRead(buttonPin);

  if (!lastButtonState && !reading) {
    lastButtonState = HIGH;
    thisMany = thisMany + 1;
    return thisMany;
  } else if (lastButtonState && reading) {
    lastButtonState = LOW;
  }
}

int Button::howManyReset() {
  thisMany = 0;
}

int Button::update() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        Serial.println("Button pressed");
        return buttonState;
      }
    }
  }
  lastButtonState = reading;
}
