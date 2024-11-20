#include <dht.h>

#define dht_apin 2

dht DHT;

void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("DHT11 Temperature Sensor\n\n");
  delay(1000);
}

void loop() {
  
  DHT.read11(dht_apin);

  
  Serial.print("Temperature: ");
  Serial.print(DHT.temperature);
  Serial.println(" °C");

  delay(5000);
}
