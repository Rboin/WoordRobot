/*
 * Robot.cpp
 *
 *  Created on: Mar 12, 2015

 *      Author: Robin
 */

#include "Robot.h"

//LedControl wordt hier geinitialiseerd omdat hij anders de default constructor (LedControl::LedControl()) aanroept die niet bestaat
Robot::Robot(Lijnsensor handler, int displayAddr) : ledControl(LedControl(12,11,10,1)) {
	this->handler = handler;
	this->displayAddr = displayAddr;
	// Initialiseer de Motoren
	this->motor = Motors();

}

bool Robot::vindReferentieLijn() {
	bool gevonden = false;
	SensorListener **sensoren = this->handler.getSensoren();
	while (!gevonden) {
		// Robot ziet helemaal niks (startpunt)
		if (!sensoren[0]->zietLijn() && !sensoren[1]->zietLijn()
				&& !sensoren[2]->zietLijn())
			this->handler.update();
		// Robot zit op een lijn
		if (sensoren[0]->zietLijn() && sensoren[1]->zietLijn()) {
			// Robot rijdt over de lijn
			this->handler.update();
			// Is de lijn dik genoeg voor alle 3 sensoren? (STOPLIJN)
			if (sensoren[0]->zietLijn() && sensoren[1]->zietLijn()
					&& sensoren[2]->zietLijn()) {
				this->motor.stoppen();
				this->motor.links(45.0);
				this->motor.rijden(2000);
				this->handler.update();
				// Of is de lijn niet dik genoeg voor alle 3 en raakt
				//	alleen de achterste de lijn? (Referentie lijn)
			} else if (!sensoren[0]->zietLijn() && !sensoren[1]->zietLijn()
					&& sensoren[2]->zietLijn()) {
				this->motor.stoppen();
				gevonden = true;
				break;
			}
		}
	}
	return gevonden;
}

/**
 * Initialisatie van de displays
 */
void Robot::initDisplay(bool b, int intensity) {
	// De MAX72XX staat in power-saving mode wanneer die opgestart wordt
	this->ledControl.shutdown(this->displayAddr, b);
	this->ledControl.setIntensity(this->displayAddr, intensity);
	this->ledControl.clearDisplay(this->displayAddr);
}

/**
 * Voorbeeld hoe je ermee werkt:
 * robot.setDisplay(1, 0, 'l', '1', false, 1000);
 * robot.setDisplay(1, 0, 'l', '2', false, 1000);
 */
void Robot::setDisplay(int digit1, int digit2, char value1, char value2, bool dp, int time) {
	long currentMillis = millis();
	long previousMillis = currentMillis;
	while (currentMillis - previousMillis < time) {
		this->ledControl.setChar(this->displayAddr, digit1, value1, dp);
		this->ledControl.setChar(this->displayAddr, digit2, value2, dp);
		currentMillis = millis();
	}
}

Motors Robot::getMotor() {
	return this->motor;
}

