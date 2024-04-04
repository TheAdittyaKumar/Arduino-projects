// Flame Detection System with Buzzer Alert
// Created by Adittya Kumar Chowdhury

int flameSensorPin = 2; // Flame sensor's digital output connected to digital pin 2
int buzzerPin = 11;     // Buzzer connected to digital pin 11
int flameDetected = 0;

void setup() {
  pinMode(flameSensorPin, INPUT); // Set the flame sensor pin as input
  pinMode(buzzerPin, OUTPUT);     // Set the buzzer pin as output
  Serial.begin(9600);             // Start serial communication at 9600 bps
}

void loop() {
  flameDetected = digitalRead(flameSensorPin); // Read the flame sensor pin
  if (flameDetected == LOW) { // If the sensor's digital output is LOW, flame is detected
    Serial.println("Flame detected!");
    digitalWrite(buzzerPin, HIGH); // Activate the buzzer
  } else {
    Serial.println("No Flame.");
    digitalWrite(buzzerPin, LOW); // Deactivate the buzzer
  }
  delay(1000); // Wait for 1 second before the next loop
}
