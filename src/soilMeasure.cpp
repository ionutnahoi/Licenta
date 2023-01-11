#include <soilMeasure.h>
#include <Arduino.h>
#define sensorPin 2
int readSensor() {
	int value=digitalRead(sensorPin);
    Serial.print("Soil sensor value: ");
    Serial.print(value);
}