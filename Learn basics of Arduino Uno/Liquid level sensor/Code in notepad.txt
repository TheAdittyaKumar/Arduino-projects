// Code by Adittya Kumar Chowdhury

// Define the pin where the sensor is connected
const int liquidLevelPin = A5;

// Initialize a counter for the reading number
unsigned long readingNumber = 0;

void setup() {
  // Initialize Serial communication at a baud rate of 9600
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

  // Output the reading number
  Serial.print("Reading Number: ");
  Serial.println(readingNumber);

  // 1) Output the liquid level status
  Serial.println("The amount of liquid is " + liquidLevel + ".");
  
  // 2) Output the raw sensor value
  Serial.println("Raw sensor value: " + String(sensorValue));
  
  // 3) Delay the reading
  delay(2000); // Delay of 2 seconds (2000 milliseconds)
  
  // 4) Create a margin after the output
  Serial.println("----------------------------");
}
