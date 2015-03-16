/*
 * SensorMidden.cpp
 *
 *  Created on: Mar 13, 2015
 *      Author: Robin
 */

#include "Arduino.h"
#include "SensorMidden.h"

SensorMidden::SensorMidden(Lijnsensor *handler, Motors motor, int pin) {

	this->motor = motor;
	this->pin = pin;
	handler->attachSensor(this, 2);
}

bool SensorMidden::zietLijn() {
	bool zietlijn = false;
	if(this->geefWaarde() > 989) {
		zietlijn = true;
	}
	return zietlijn;
}

int SensorMidden::geefWaarde() {
	return analogRead(this->pin);
}

void SensorMidden::onDetect() {
	while (this->zietLijn()) {
		motor.rijden();
	}
}
