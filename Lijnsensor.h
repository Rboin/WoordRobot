/*
  Lijnsensor.h
  WJT01
*/
#ifndef Lijnsensor_h
#define Lijnsensor_h

#include "Arduino.h"

class Lijnsensor
{
  public:
    Lijnsensor(int pin);
    int geefWaarde();
    bool zietLijn();
    void printSerial();
  private:
    int _pin;
    int _waarde;
};

#endif
