// Code by Adittya Kumar Chowdhury
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
}

void loop() {
  myservo.write(0);   // tell servo to go to position 0
  Serial.println("Servo rotated to 0 degrees");
  delay(3000);        // wait for 3 seconds
  
  myservo.write(90);  // tell servo to go to position 90
  Serial.println("Servo rotated to 90 degrees");
  delay(3000);        // wait for 3 seconds
  
  myservo.write(180); // tell servo to go to position 180
  Serial.println("Servo rotated to 180 degrees");
  delay(3000);        // wait for 3 seconds
  
  // Reverse sequence
  myservo.write(90);  // tell servo to go back to position 90
  Serial.println("Servo rotated back to 90 degrees");
  delay(3000);        // wait for 3 seconds
  
  // It will then loop back to the start and go to 0 degrees as part of the loop's restart
}
