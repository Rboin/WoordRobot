/*
 Lijnsensor.cpp
 WJT
 */

#include "Arduino.h"
#include "Lijnsensor.h"

void Lijnsensor::attachSensor(SensorListener* listener, int index) {
	this->sensoren[index] = listener;
}

SensorListener** Lijnsensor::getSensoren() {
	return this->sensoren;
}

void Lijnsensor::update() {
	for(unsigned int i = 0; i < 3; i++) {

		Serial.println(i);
		Serial.println(this->sensoren[i]->geefWaarde());
		this->sensoren[i]->onDetect();
		delay(1000);
	}
}
