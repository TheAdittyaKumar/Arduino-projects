#include <SoftwareSerial.h>

const int trigPin = 10;
const int echoPin = 11;
const int mq2Pin = A0; // Analog pin for MQ2 gas sensor
const int liquidLevelPin = A1; // Analog pin for liquid level sensor
const int fireSensorPin = A2; // Analog pin for fire sensor

long duration;
int distance;
int gasValue;
int thresholdValue = 500; // Adjust this threshold value according to your needs

char command;

SoftwareSerial BTserial(2, 3); // SoftwareSerial pins

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  
  Serial.begin(9600);       // Starts the serial communication 
  BTserial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
  }

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2;
  
  // Print delimiter
  Serial.println("----------------------------");
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Reading the gas value from MQ2 sensor
  gasValue = analogRead(mq2Pin);
  
  // Prints the gas value on the Serial Monitor
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // Reading the liquid level sensor value
  int liquidLevelValue = analogRead(liquidLevelPin);
  
  // Prints the liquid level sensor value on the Serial Monitor
  Serial.print("Liquid Level: ");
  Serial.println(liquidLevelValue);

  // Reading the fire sensor value
  int fireSensorValue = analogRead(fireSensorPin);
  
  // Prints the fire sensor value on the Serial Monitor
  Serial.print("Fire Sensor Value: ");
  Serial.println(fireSensorValue);

  // Add your gas detection logic here
  if (gasValue > thresholdValue) {
    // Gas detected, take appropriate action
    Serial.println("Gas detected!");
    // Add your code to handle the gas detection event
  }

  // Delay for 5 seconds (5000 milliseconds)
  delay(5000);
}