// PIR sensor and buzzer project
// Code by Adittya Kumar Chowdhury

// Define the pins for the PIR sensor and the buzzer
const int pirPin = 2; // Pin connected to the PIR sensor's output
const int buzzerPin = 11; // Pin connected to the buzzer (changed to pin 11)

void setup() {
  pinMode(pirPin, INPUT); // Initialize the PIR sensor pin as an input
  pinMode(buzzerPin, OUTPUT); // Initialize the buzzer pin as an output
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  int pirValue = digitalRead(pirPin); // Read the value from the PIR sensor
  if (pirValue) { // If the PIR sensor detects motion
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    Serial.println("Motion detected!"); // Send a message to the serial monitor
    delay(1000); // Keep the buzzer on for 1 second
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
  } else {
    digitalWrite(buzzerPin, LOW); // Ensure the buzzer is off if no motion is detected
  }
  delay(100); // Short delay before the next loop iteration
}
