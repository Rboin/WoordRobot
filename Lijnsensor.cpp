/*
 Lijnsensor.cpp
 WJT
 */

#include "Arduino.h"
#include "Lijnsensor.h"

Lijnsensor::Lijnsensor() {}
Lijnsensor::Lijnsensor(int pin) {
	_pin = pin;
	_waarde = analogRead(_pin);
}

int Lijnsensor::geefWaarde() {
	return this->_waarde;
}

bool Lijnsensor::zietLijn() {
	if (analogRead(_pin) > 1000)
		return true;
	else
		return false;
}

void Lijnsensor::printSerial() {
	Serial.print(this->geefWaarde());
}
