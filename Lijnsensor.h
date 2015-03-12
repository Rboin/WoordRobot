/*
 Lijnsensor.h
 WJT01
 */
#ifndef Lijnsensor_h
#define Lijnsensor_h

#include "Arduino.h"
//#include "Motors.h"

class Lijnsensor {
public:
	// Default constructor aangemaakt vanwege declaratie in Robot.h
	Lijnsensor();
	Lijnsensor(int pin);
	int geefWaarde();
	bool zietLijn();
	void printSerial();
private:
	int _pin;
	int _waarde;
};

#endif
