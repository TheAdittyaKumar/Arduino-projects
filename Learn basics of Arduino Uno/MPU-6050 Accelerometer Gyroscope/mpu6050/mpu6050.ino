#include <Wire.h>
#include <MPU6050.h>
#include <Mouse.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;

const int buttonPin = 2; // Button connected to digital pin 2

void setup() {
    Serial.begin(9600);
    pinMode(buttonPin, INPUT_PULLUP); // Initialize the button pin as an input with an internal pull-up resistor
    Wire.begin();
    Serial.println("I2C begin");
    mpu.initialize();
    Serial.println("MPU Sensor Initializing...");
    if (!mpu.testConnection()) {
        while (1); // Wait here infinitely till sensor initializes.
    }
    Serial.println("Sensor initialized");
}

void loop() {
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    vx = -(gx+250)/150; // change 300 from 0 to 355
    vy = (gy+250)/150; // same here about -100 from -355 to 0

    // Read the state of the button
    int buttonState = digitalRead(buttonPin);

    // Check if button is pressed (button state will be LOW if pressed due to pull-up)
    if (buttonState == LOW) {
        // Simulate a mouse click
        Mouse.press(MOUSE_LEFT);
        delay(100); // This delay represents the duration of the click
        Mouse.release(MOUSE_LEFT);
        delay(200); // This delay is to debounce and to prevent a rapid-fire click
    }

    // Uncomment the line below to enable mouse movement
     Mouse.move(vx, vy);

    delay(200); // Delay at the end of the loop
}
