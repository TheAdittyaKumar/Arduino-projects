#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int fireSensorPin = 2;
const int buzzerPin = 11;

// Define custom characters for the running man animation
byte runningMan1[8] = {
  0b00100,
  0b01110,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010,
  0b10001
};

byte runningMan2[8] = {
  0b00100,
  0b01110,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010,
  0b01010
};

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(fireSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Create the custom characters
  lcd.createChar(0, runningMan1);
  lcd.createChar(1, runningMan2);
}

void loop() {
  int sensorState = digitalRead(fireSensorPin);

  lcd.clear();
  if (sensorState == LOW) {
    lcd.print("Fire Detected!");
    digitalWrite(buzzerPin, HIGH);

    // Display the running man animation
    for (int position = 0; position < 16; position++) {
      lcd.setCursor(position, 1); // Set cursor to bottom row
      lcd.write((position % 2) == 0 ? 0 : 1); // Alternate between custom characters
      delay(300);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire Detected!");
    }
  } else {
    lcd.print("No Fire Detected");
    digitalWrite(buzzerPin, LOW);
    // Make sure the second line is clear
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }
  delay(500);
}
