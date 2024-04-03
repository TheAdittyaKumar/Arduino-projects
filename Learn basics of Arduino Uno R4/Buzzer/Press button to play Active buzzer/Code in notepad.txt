// Code by Adittya Kumar Chowdhury

// This code allows you to play the buzzer when you push the button in your 2 pin push button

// Define pin connections & variables
const int buttonPin = 2; // Pin connected to the push button
const int buzzerPin = 9; // Pin connected to the buzzer

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
}

void loop() {
  // Read the state of the button
  int buttonState = digitalRead(buttonPin);

  // Check if button is pressed
  if (buttonState == LOW) { // When the button is pressed (circuit closed), it reads LOW
    digitalWrite(buzzerPin, LOW); // Turn buzzer off
  } else {
    digitalWrite(buzzerPin, HIGH); // Turn buzzer on
  }
}
