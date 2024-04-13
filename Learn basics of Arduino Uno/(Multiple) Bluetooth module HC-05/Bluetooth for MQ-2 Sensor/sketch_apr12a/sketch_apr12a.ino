// Define the pin where the MQ-2 sensor is connected
const int mq2SensorPin = A0;

void setup() {
  // Initialize Serial communication at a baud rate of 9600
  // This is also used for Bluetooth communication with the HC-05 module
  Serial.begin(9600);
}

void loop() {
  // Read the sensor value from the MQ-2 gas sensor
  int sensorValue = analogRead(mq2SensorPin);

  // Send the raw sensor value over Bluetooth
  Serial.print("MQ-2 Sensor Value: ");
  Serial.println(sensorValue);

  // Delay before the next reading
  delay(1000); // Delay of 1 second
}
