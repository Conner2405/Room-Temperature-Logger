#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN A0
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("========== Temperature Reading Program ==========");
  Serial.println("This program reads temperature from the DHT11 sensor.");
  
  dht.begin();
  Serial.println("DHT sensor initialized. Ready to read temperature!");
  Serial.println("---------------------------------------------------");
}

void loop() {
  Serial.println("Reading temperature from the DHT sensor...");

  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("[ERROR] Failed to read temperature from the DHT sensor!");
    Serial.println("Possible issues: check the wiring or the sensor itself.");
    delay(2000);
    return;
  }

  Serial.println("[SUCCESS] Temperature successfully read!");
  Serial.print("-> Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.println("---------------------------------------------------");

  delay(2000);
}
