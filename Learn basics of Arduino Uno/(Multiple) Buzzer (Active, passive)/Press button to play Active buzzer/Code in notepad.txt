// Code by Adittya Kumar Chowdhury

// This code allows you to play the buzzer when you push the button on your 2 pin push button and outputs the status to the serial monitor.

// Define pin connections & variables
const int buttonPin = 2; // Pin connected to the push button
const int buzzerPin = 9; // Pin connected to the buzzer

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second
}

void loop() {
  // Read the state of the button
  int buttonState = digitalRead(buttonPin);

  // Check if button is pressed
  if (buttonState == LOW) { // When the button is pressed (circuit closed), it reads LOW
    digitalWrite(buzzerPin, LOW); // Turn buzzer on
    Serial.println("---------------");
    Serial.println("Button pressed, buzzer on!");
    Serial.println("---------------");
  } else {
    digitalWrite(buzzerPin, HIGH); // Turn buzzer off
    Serial.println("---------------");
    Serial.println("Button not pressed, buzzer off.");
    Serial.println("---------------");
  }

  // Delay a bit to avoid bouncing issues and to not flood the serial monitor
  delay(200);
}
