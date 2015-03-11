/*
 Lijnsensor.cpp
 WJT
 */

#include "Arduino.h"
#include "Lijnsensor.h"

Lijnsensor::Lijnsensor(int pin) {
	_pin = pin;
}

int Lijnsensor::geefWaarde() {
	_waarde = analogRead(_pin);
	return _waarde;
}

bool Lijnsensor::zietLijn() {
	if (analogRead(_pin) > 1000)
		return true;
	else
		return false;
}

void Lijnsensor::printSerial() {
	Serial.println(this->geefWaarde());
}
