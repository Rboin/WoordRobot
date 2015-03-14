/*
 Lijnsensor.cpp
 WJT
 */

#include "Arduino.h"
#include "Lijnsensor.h"

void Lijnsensor::attachSensor(SensorListener *listener, int index) {
	this->sensoren[index] = listener;
}

SensorListener **Lijnsensor::getSensoren() {
	return this->sensoren;
}

void Lijnsensor::update() {
	for(int i = 0; i < sizeof(this->sensoren); i++) {
		this->sensoren[i]->onDetect();
	}
}
