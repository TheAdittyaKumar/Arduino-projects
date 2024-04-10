#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the connection pins
#define TRIGGER_PIN  10
#define ECHO_PIN     11
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters)

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);              // Open serial console.
}

void loop() {
  delay(50);                       // Wait 50ms between pings (about 20 pings/sec).
  unsigned int uS = sonar.ping();  // Send ping, get ping time in microseconds (uS).
  unsigned int distance = uS / US_ROUNDTRIP_CM;  // Convert time into distance
  lcd.clear();                     // Clear the display
  lcd.setCursor(0, 0);             // Set the cursor to the top-left position
  lcd.print("Distance: ");
  lcd.setCursor(0, 1);             // Move to the second line
  lcd.print(distance);
  lcd.print(" cm");
  Serial.print("Ping: ");
  Serial.print(distance); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}