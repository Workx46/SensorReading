#include <SensorRead.h>

Sensor mySensor;

void setup()
{
  Serial.begin(9600);
  mySensor.pin(A0, "PullUp");
}

void loop()
{
  Serial.println(mySensor.avgRead("digital"));
  delay(100);
}
