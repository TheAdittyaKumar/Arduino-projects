int Sensor = A0; // Sound sensor connected to A0
int clapCount = 0; // Variable to keep track of claps
long lastClapTime = 0; // Last time a clap was detected
long ledOnTime = 0; // Time when the LED was turned on
boolean ledState = false; // State of the LED, initially off

void setup() {
  pinMode(Sensor, INPUT); // Set sound sensor pin as input
  pinMode(13, OUTPUT); // Set LED pin as output
  Serial.begin(9600); // Start serial communication for debugging
  Serial.println("System Ready. Waiting for claps...");
}

void loop() {
  int statusSensor = analogRead(Sensor);

  // Check if the sensor reading goes over 100, indicating a potential clap
  if (statusSensor > 100) {
    long currentTime = millis();

    // Check for a minimum gap of 400ms between claps to avoid noise
    if (currentTime - lastClapTime > 400) {
      // Record the time of the clap
      lastClapTime = currentTime;
      
      // Increase clap count
      clapCount++;

      // Print to the Serial Monitor that a clap was detected
      Serial.println("Clap detected!");
      Serial.print("Clap number: ");
      Serial.println(clapCount);
      Serial.println("-----"); // Separator for clarity
      
      // Light up the LED for 2 seconds
      digitalWrite(13, HIGH); // Turn LED on
      ledOnTime = currentTime; // Record the time LED was turned on
      ledState = true; // Set the LED state to on
    }
  }

  // Turn off the LED after 2 seconds if it is currently on
  if (ledState && (millis() - ledOnTime > 2000)) {
    digitalWrite(13, LOW); // Turn off the LED
    ledState = false; // Update the LED state
  }

  delay(10); // Short delay to debounce and prevent reading the sensor too quickly
}
