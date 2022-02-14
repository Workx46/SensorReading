#include <SensorRead.h>

Sensor mySensor;

void setup()
{
  Serial.begin(9600);
  mySensor.setAVG(30);
  mySensor.pin(A0);
}

void loop()
{
  Serial.println(mySensor.avgRead());
  delay(100);
}
