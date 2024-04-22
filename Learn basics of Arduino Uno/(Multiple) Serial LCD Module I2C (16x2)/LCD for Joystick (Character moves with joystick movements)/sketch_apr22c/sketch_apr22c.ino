#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD and set its address, usually either 0x27 or 0x3F for a 16 cols and 2 rows display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Joystick connections
int joystickX = A0;  // VRx
int joystickY = A1;  // VRy
int joystickButton = 2;   // SW

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();

  // Initialize the joystick button as an input
  pinMode(joystickButton, INPUT_PULLUP);

  // Clear the LCD and set the initial cursor position
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("*"); // This character represents the player
}

void loop() {
  static int characterPositionX = 0;
  static int characterPositionY = 0;
  
  // Read joystick position
  int xValue = analogRead(joystickX);
  int yValue = analogRead(joystickY);
  bool buttonPressed = digitalRead(joystickButton) == LOW;

  // Determine the character's new position based on the joystick position
  if (xValue < 400) { // Move left
    characterPositionX = max(characterPositionX - 1, 0);
  } else if (xValue > 600) { // Move right
    characterPositionX = min(characterPositionX + 1, 15);
  }

  if (yValue < 400) { // Move down
    characterPositionY = 1;
  } else if (yValue > 600) { // Move up
    characterPositionY = 0;
  } else if (buttonPressed) { // Jump or additional action
    characterPositionY = 0; // Make the character jump to the first row
    // Implement any additional jump logic here
  }

  // Update the LCD with the new character position
  lcd.clear();
  lcd.setCursor(characterPositionX, characterPositionY);
  lcd.print("*");

  // Delay to prevent bouncing/jittering
  delay(100);
}
