// Code by Adittya Kumar Chowdhury

// Define the pin where the sensor is connected
const int liquidLevelPin = A5;

// Initialize a counter for the reading number
unsigned long readingNumber = 0;

void setup() {
  // Initialize Serial communication at a baud rate of 9600
  // This is also used for Bluetooth communication with the HC-05 module
  Serial.begin(9600);
}

void loop() {
  // Increment the reading number
  readingNumber++;

  // Read the sensor value from the liquid level sensor
  int sensorValue = analogRead(liquidLevelPin);

  // Determine the liquid level based on the sensor value
  String liquidLevel;
  if(sensorValue > 700) { // Assume >700 for High level, adjust based on your calibration
    liquidLevel = "High";
  } else if(sensorValue > 400) { // Assume >400 for Medium level, adjust based on your calibration
    liquidLevel = "Medium";
  } else if(sensorValue > 100) { // Assume >100 for Low level, adjust based on your calibration
    liquidLevel = "Low";
  } else {
    liquidLevel = "None";
  }

  // Send the liquid level status over Bluetooth
  Serial.print("Reading Number: ");
  Serial.println(readingNumber);
  Serial.print("Liquid Level: ");
  Serial.println(liquidLevel);
  Serial.print("Raw Sensor Value: ");
  Serial.println(sensorValue);
  
  // Delay the reading
  delay(2000); // Delay of 2 seconds
}
