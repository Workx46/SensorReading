#ifndef SensorRead_h
#define SensorRead_h

#include "Arduino.h"

class Sensor
{
  public:
    uint8_t pin(int pin, String mode);
	uint8_t pin(int pin);
    int avgRead(String mode);
	int avgRead();
	uint8_t setAVG(int avg);
  private:
    int _pin;
    long SensorValueAccumlated;
    int counter;
    long count_no = 0;
    int value;
	bool lastState = 0;
	bool val = 0;
	bool val2 = 0;
};

#endif
