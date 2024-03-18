// Code by Adittya Kumar Chowdhury
// When motion is detected, an LED lights up for 5 seconds and a buzzer sounds for 2 seconds.

int ledPin = 13;               // the pin that the LED is attached to
int sensorPin = 2;             // the pin that the sensor is attached to
int buzzerPin = 8;             // the pin that the buzzer is attached to
int sensorState = LOW;         // by default, no motion detected
unsigned long lastMotionTime = 0; // the last time motion was detected
unsigned long lastBuzzerTime = 0; // the last time the buzzer was activated
bool buzzerActive = false;     // track whether the buzzer is currently active

void setup() {
  pinMode(ledPin, OUTPUT);     // initialize LED as an output
  pinMode(buzzerPin, OUTPUT);  // initialize buzzer as an output
  pinMode(sensorPin, INPUT);   // initialize sensor as an input
  Serial.begin(9600);          // initialize serial
}

void loop() {
  int sensorValue = digitalRead(sensorPin);  // read sensor value
  unsigned long currentTime = millis();
  
  if (sensorValue == HIGH) {             // check if the sensor is HIGH
    if (sensorState == LOW) {
      Serial.println("Motion detected!");
      sensorState = HIGH;                // update variable state to HIGH
      lastMotionTime = currentTime;     // update the last motion time
      lastBuzzerTime = currentTime;     // reset the buzzer timer
      buzzerActive = true;              // activate the buzzer
    }
  }
  
  // Manage LED timing
  if (currentTime - lastMotionTime <= 5000) { // If less than 5 seconds have passed
    digitalWrite(ledPin, HIGH);               // Keep the LED ON
  } else {
    digitalWrite(ledPin, LOW);                // Turn the LED OFF
  }
  
  // Manage buzzer timing
  if (buzzerActive && currentTime - lastBuzzerTime <= 2000) { // If less than 2 seconds have passed
    digitalWrite(buzzerPin, HIGH);            // Keep the buzzer ON
  } else {
    digitalWrite(buzzerPin, LOW);             // Turn the buzzer OFF
    buzzerActive = false;                     // Deactivate the buzzer
  }

  // Reset sensor state if no motion is detected and actions have concluded
  if (sensorValue == LOW && currentTime - lastMotionTime > 5000 && !buzzerActive) {
    if (sensorState == HIGH) {
      Serial.println("Motion stopped!");
      sensorState = LOW;                      // Update variable state to LOW
    }
  }
}
