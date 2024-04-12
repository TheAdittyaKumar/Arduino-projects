// defines pins numbers for the ultrasonic sensor
const int trigPin = 10;
const int echoPin = 11;

// defines variables for the ultrasonic sensor
long duration;
int distance;

void setup() {
  // Setup for the ultrasonic sensor
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  
  // Starts serial communication for debugging and communication with the HC-05
  Serial.begin(9600);
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor for debugging
  Serial.print("Distance: ");
  Serial.println(distance);

  // Check for input from Bluetooth (HC-05)
  if(Serial.available() > 0) {
    char data = Serial.read(); // reading the data received from the bluetooth module
    if(data == 's') { // If 's' is sent from the connected Bluetooth device
      // Send the distance value over Bluetooth
      Serial.print("Distance: ");
      Serial.println(distance);
    }
  }
  
  delay(50); // Short delay before the next reading
}
