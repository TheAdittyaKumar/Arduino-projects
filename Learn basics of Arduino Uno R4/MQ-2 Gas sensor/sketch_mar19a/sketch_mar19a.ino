int mq2Pin = A0; // MQ-2 sensor connected to analog pin A0
int threshold = 700; // Set this to the threshold for smoke detection

// Setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); // Start the serial communication
}

// Loop function runs over and over again forever
void loop() {
  int sensorValue = analogRead(mq2Pin); // Read the analog value from the sensor
  Serial.print("Gas value: "); // Print the text
  Serial.println(sensorValue); // Print the sensor value to the Serial Monitor
  
  // Check if the gas value goes above the threshold
  if (sensorValue > threshold) {
    Serial.println("Smoke detected!"); // Print the detection message to the Serial Monitor
  }
  
  delay(2000); // Wait for 2 seconds (2000 milliseconds) before reading again
}

// Code by Adittya Kumar Chowdhury
