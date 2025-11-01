#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>


/*
  Constants:

  - Using the Adafruit library as the bme 
  - Standard sea level pressure value
  - GIOP pin that is connected to the data wire
  - GIOP pin that is connected to the serial clock wire
*/
Adafruit_BME280 bme;
const int SEA_LEVEL_PRESSURE_HPA = 1013.25;
const int SDA_PIN = 21;
const int SCL_PIN = 22;



/*
  Setting up method that is responsible for initializing
  the serial monitor, I2C communication protocol, and
  the BME280 sensor at the specified address.
*/
void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("Testing BME");

  if(!bme.begin(0x76)) {
    Serial.println("Failed communicating with the sensor over I2C");
  }
}

/*
  Infinite loop that prints the temperature, humidity, pressure,
  and the altitude reading from the BME280 sensor every 7 seconds.
*/
void loop() {
  Serial.printf("Temperature = %.2f°C\n", bme.readTemperature());
  Serial.printf("Humidity = %.2f%%\n", bme.readHumidity());
  Serial.printf("Pressure = %.2f hPa\n", bme.readPressure() / 100);
  Serial.printf("Altitude = %.2fm\n", bme.readAltitude(SEA_LEVEL_PRESSURE_HPA));
  Serial.println("===================");
  delay(7000);
}
