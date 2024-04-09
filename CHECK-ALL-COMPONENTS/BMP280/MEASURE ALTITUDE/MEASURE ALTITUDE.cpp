//in this section we will just measure the altitude  

#include<Arduino.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>

#define ALTITUDE_REFERENCE 0 // Initial altitude at ground level
#define SEA_LEVEL_PRESSURE 1000 // Sea level pressure in hPa

Adafruit_BMP280 bmp; // Create BMP280 object

void setup() {
  Serial.begin(9600);
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
}

void loop() {
  float pressure = bmp.readPressure(); // Read pressure from sensor
  float altitude = bmp.readAltitude(SEA_LEVEL_PRESSURE); // Calculate altitude relative to sea level pressure

  altitude -= ALTITUDE_REFERENCE; // Calculate altitude relative to initial position

  

  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println(" meters");

  delay(1000); // Delay for 1 second
}
