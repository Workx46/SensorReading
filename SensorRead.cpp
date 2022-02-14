#include "Arduino.h"
#include "SensorRead.h"

uint8_t Sensor::pin(int pin, String mode)
{
  if(mode == "PullUp"){
    pinMode(pin, INPUT_PULLUP);
  } 
  lastState = digitalRead(pin);
  _pin = pin;
}

uint8_t Sensor::pin(int pin)
{
  pinMode(pin, INPUT);
  lastState = digitalRead(pin);
  _pin = pin;
}

int Sensor::avgRead(String mode)
{
  if(mode == "digital"){
    val = digitalRead(_pin);
	if(val != lastState){
	  delay(15);
	  val2 = digitalRead(_pin);
	  if(val == val2){
		lastState = val;
		counter ++;
	  }
	}
	if(counter == 2){
	  counter = 0;
	}
  } 
  value = val;
  return value;
}

int Sensor::avgRead()
{
  SensorValueAccumlated += analogRead(_pin);
  if (counter == count_no){
    value = int(float(SensorValueAccumlated / count_no));
    SensorValueAccumlated = 0;
    counter = 0;
    return value;
  }
  counter++;
}

uint8_t Sensor::setAVG(int avg)
{
  count_no = avg;
}