/*
 * SensorRechts.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: Robin
 */


#include "Arduino.h"
#include "SensorRechts.h"

SensorRechts::SensorRechts(Lijnsensor *handler, Motors motor, int pin) {

	this->motor = motor;
	this->pin = pin;
	handler->attachSensor(this, 1);
}

bool SensorRechts::zietLijn() {
	bool zietlijn = false;
	if(this->geefWaarde() > 989) {
		zietlijn = true;
	}
	return zietlijn;
}


int SensorRechts::geefWaarde() {
	return analogRead(this->pin);
}

void SensorRechts::onDetect() {
	while (this->zietLijn()) {
		motor.rechts(10.0);
	}
}
