/*
Arduino Thermostat

Developed by Henry Hall

Connections:
DHT11: 12
Heating device: 0
Cooling device: 1

Details:
Platfrom: nRF52833
Framework: Arduino
Board: micro:bit
*/

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 12

#define DHTTYPE DHT11

const int heatPin = 0;
const int coolPin = 1;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  pinMode(heatPin, OUTPUT);
  pinMode(coolPin, OUTPUT);
  
  Serial.begin(9600);
  Serial.println(F("Arduino Thermostat"));

  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hif = dht.computeHeatIndex(f, h);

  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  if (t < 24) {
    digitalWrite(heatPin, HIGH);
    digitalWrite(coolPin, LOW);
  }
  else {
    digitalWrite(heatPin, LOW);
    digitalWrite(coolPin, HIGH);
  }
}
