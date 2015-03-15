/*
 * SensorLinks.cpp
 *
 *  Created on: Mar 13, 2015
 *      Author: Robin
 */

#include "Arduino.h"
#include "SensorLinks.h"

SensorLinks::SensorLinks(Lijnsensor handler, Motors motor, int pin) {

	this->motor = motor;
	this->pin = pin;
	handler.attachSensor(this, 1);
}

bool SensorLinks::zietLijn() {
	bool zietlijn = false;
	if(this->geefWaarde() > 1000) {
		zietlijn = true;
	}
	return zietlijn;
}


int SensorLinks::geefWaarde() {
	return analogRead(this->pin);
}

void SensorLinks::onDetect() {
	while (this->zietLijn()) {
		motor.rechts(10.0);
	}
}
