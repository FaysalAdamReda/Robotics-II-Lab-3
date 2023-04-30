#include "Button.h"

// Define the button pin and debounce delay
const int buttonPin = 2;
const int debounceDelay = 50;

// Create a Button object
Button button(buttonPin, debounceDelay);

void setup() {
  // No setup required for this example
  Serial.begin(9600);
}

void loop() {
  // Call the update method of the Button object
  button.update();
  
}
