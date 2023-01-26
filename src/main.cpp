#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 15 // Digital pin connected to the DHT sensor
#define soil 2 //Digital soil measure pin
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

#define DHTTYPE DHT11 // DHT 11

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;
sensor_t sensor;

int _moisture, sensor_analog;

float get_temperature()
{

  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature))
  {
    Serial.println(F("Error reading temperature!"));
  }
  else
  {
    return event.temperature;
  }
}
int get_humidity()
{
  sensors_event_t event;

  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity))
  {
    Serial.println(F("Error reading humidity!"));
  }
  else
  {
    return event.relative_humidity;
  }
}
int mousure_sensor()
{
  _moisture = (100 - ((sensor_analog / 4095.00) * 100));
  return _moisture;
}
void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(2, INPUT);
  pinMode(15, INPUT);
}

void loop()
{
  delay(1000);

  sensor_analog = analogRead(soil);
  Serial.printf("\nUmiditate sol:%d % ",mousure_sensor());

  Serial.printf("\nTemperatura: %f Celsius",get_temperature());

  Serial.printf("\nHumidity: %d ",get_humidity());

  delay(1000);
}