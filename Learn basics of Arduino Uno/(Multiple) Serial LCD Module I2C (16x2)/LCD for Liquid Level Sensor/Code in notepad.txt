#include <LiquidCrystal_I2C.h>

// Liquid level sensor code by Adittya Kumar Chowdhury

// Initialize the LCD on address 0x27 with 16 characters and 2 lines
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the pin where the sensor is connected
const int liquidLevelPin = A0;

// Calibrated sensor values for different levels
const int SENSOR_HIGH = 900;   // Value for high level, adjust this as per your calibration
const int SENSOR_MEDIUM = 600; // Value for medium level, adjust this as per your calibration
const int SENSOR_LOW = 300;    // Value for low level, adjust this as per your calibration

void setup() {
  lcd.init();                    // Initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);            // Initialize Serial communication at a baud rate of 9600
}

void loop() {
  // Read the sensor value from the liquid level sensor
  int sensorValue = analogRead(liquidLevelPin);

  // Determine the liquid level based on the sensor value
  String liquidLevel;
  if(sensorValue > SENSOR_HIGH) {
    liquidLevel = "High";
  } else if(sensorValue > SENSOR_MEDIUM) {
    liquidLevel = "Medium";
  } else if(sensorValue > SENSOR_LOW) {
    liquidLevel = "Low";
  } else {
    liquidLevel = "None";
  }

  // Display the liquid level status on the LCD
  lcd.clear();                   // Clear the LCD
  lcd.setCursor(0, 0);           // Set the cursor to the beginning of the first line
  lcd.print("Liquid Level:");
  lcd.setCursor(0, 1);           // Set the cursor to the beginning of the second line
  lcd.print(liquidLevel);

  // Output the raw sensor value and liquid level to the serial monitor
  Serial.print("Liquid Level: ");
  Serial.print(liquidLevel);
  Serial.print(", Raw Value: ");
  Serial.println(sensorValue);
  
  delay(2000); // Delay for 2 seconds before the next reading
}
