// Soil moisture sensor reading code by Adittya Kumar Chowdhury using YL-69 

// Define the thresholds for the soil moisture levels
const int VERY_DRY = 800; // Value for very dry soil
const int MODERATELY_DRY = 600; // Value for moderately dry soil
const int MODERATELY_WET = 400; // Value for moderately wet soil
const int VERY_WET = 200; // Value for very wet soil

int Moisture_signal = A0; // Analog pin for the soil moisture sensor signal
int readingNumber = 0; // Initialize a counter for the reading number

void setup() {
  Serial.begin(9600); // Start serial communication with HC-05
}

void loop() {
  readingNumber++; // Increment reading number
  int Moisture = analogRead(Moisture_signal);  // Read the value from the sensor
  float MoisturePercent = 100.0 * (1023 - Moisture) / 1023; // Calculate moisture percentage
  
  // Send data over Bluetooth
  Serial.print("Reading Number: ");
  Serial.println(readingNumber);
  Serial.print("Soil Moisture Level: ");
  Serial.println(Moisture);
  Serial.print("Moisture Percentage: ");
  Serial.println(MoisturePercent);

  // Check for various conditions of soil moisture
  if (Moisture >= VERY_DRY) {
    Serial.println("Condition: Soil is very dry.");
  } else if (Moisture >= MODERATELY_DRY && Moisture < VERY_DRY) {
    Serial.println("Condition: Soil is moderately dry.");
  } else if (Moisture >= MODERATELY_WET && Moisture < MODERATELY_DRY) {
    Serial.println("Condition: Soil is moderately wet.");
  } else if (Moisture < MODERATELY_WET) {
    Serial.println("Condition: Soil is very wet.");
  }

  // Line break after each set of readings
  Serial.println("-------------------------------");
  
  delay(2000); // Wait for 2 seconds before taking another reading
}
