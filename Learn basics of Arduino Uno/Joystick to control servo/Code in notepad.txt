#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int joystickX = A0; // Joystick X-axis connected to A0
const int joystickY = A1; // Joystick Y-axis connected to A1

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
}

void loop() {
  int xPosition = analogRead(joystickX); // Read the joystick X-axis position
  // Map the joystick position (0 to 1023) to an angle between 0 and 180 degrees
  int angle = map(xPosition, 0, 1023, 0, 180);
  
  myservo.write(angle); // set servo position according to the joystick position
  
  // Optional: print the servo position to the Serial Monitor
  Serial.print("Servo angle set to: ");
  Serial.print(angle);
  Serial.println(" degrees");

  delay(15); // Delay a short while to stabilize the reading
}
