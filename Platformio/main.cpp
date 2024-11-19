#include <Arduino.h>
int clockPin = 2;   // Pin for clock signal (connected to a button or internal clock)
int Q1 = 12;        // Output pin for Q1 (flip-flop 1)
int Q2 = 13;        // Output pin for Q2 (flip-flop 2)
int stateQ1 = 0;    // Internal state of flip-flop 1
int stateQ2 = 0;    // Internal state of flip-flop 2

void setup() {
  pinMode(clockPin, INPUT_PULLUP);  // Clock input (button or internal clock)
  pinMode(Q1, OUTPUT);  // Output for Q1 (LED1)
  pinMode(Q2, OUTPUT);  // Output for Q2 (LED2)
}

void loop() {
  // Detect clock pulse (button press or internal clock)
  if (digitalRead(clockPin) == LOW) {
    delay(1000);  // Debounce delay

    // JK flip-flop behavior (Toggle both Q1 and Q2)
    stateQ1 = !stateQ1;  // Toggle Q1
    if (stateQ1 == 0) {
      stateQ2 = !stateQ2;  // Toggle Q2 when Q1 transitions from 1 to 0
    }

    // Update the outputs (LEDs or logic states)
    digitalWrite(Q1, stateQ1);
    digitalWrite(Q2, stateQ2);

    // Wait for the button to be released to avoid multiple toggles
    while (digitalRead(clockPin) == LOW) {}
  }
}

