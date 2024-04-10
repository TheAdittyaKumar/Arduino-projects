#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2         // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11    // DHT 11
DHT dht(DHTPIN, DHTTYPE);

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin();
  lcd.init();  // Initialize the lcd
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();    // Read humidity
  float t = dht.readTemperature(); // Read temperature as Celsius

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DHT11 error");
  } else {
    // Display the readings on the LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print("C");
  }

  // You can also send the data to the serial monitor if needed
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
}
