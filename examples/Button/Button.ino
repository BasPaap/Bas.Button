/*
  Bas.Button
    
  This example code is in the public domain.  
*/

#include<Bas.Button.h>

const int buttonPin = 2;  // the number of the pushbutton pin
const unsigned long debounceDelay = 50; // Amount of milliseconds to debounce

Bas::Button button{ buttonPin, debounceDelay, Bas::Button::LogLevel::none };    // Instantiate a Button object with the correct pin and debouncedelay, and set the log level to none to prevent it from writing event logs to Serial.

void setup() {
    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    while (!Serial);  // wait for serial port to connect. Needed for native USB port only

    button.begin(onButtonPressed, onButtonReleased);
}

void loop() {
    // read the state of the switch into a local variable:
    button.update();    // The button needs to be updated on each loop to be responsive.
}

/// <summary>
/// This method will be called when the pushbutton is pushed.
/// </summary>
void unButtonPressed()
{
    Serial.println("Button pushed down.");
}

/// <summary>
/// This method will be called when the pushbutton is released.
/// </summary>
void unButtonReleased()
{
    Serial.println("Button released.");
}