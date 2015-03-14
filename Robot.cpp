/*
 * Robot.cpp
 *
 *  Created on: Mar 12, 2015

 *      Author: Robin
 */

#include "Robot.h"

Robot::Robot(Lijnsensor handler) {
	this->handler = handler;
	// Initialiseer de Motoren
	motor = Motors();
}


bool Robot::vindReferentieLijn() {
	bool gevonden = false;
	SensorListener **sensoren = this->handler.getSensoren();
	while (!gevonden) {
		// Robot ziet helemaal niks (startpunt)
		if (!sensoren[1]->zietLijn() && !sensoren[2]->zietLijn()
				&& !sensoren[3]->zietLijn())
			this->handler.update();
		// Robot zit op een lijn
		if (sensoren[1]->zietLijn() && sensoren[2]->zietLijn()) {
			// Robot rijdt over de lijn
			this->handler.update();
			// Is de lijn dik genoeg voor alle 3 sensoren? (STOPLIJN)
			if (sensoren[1]->zietLijn() && sensoren[2]->zietLijn()
					&& sensoren[3]->zietLijn()) {
				this->motor.stoppen();
				this->motor.links(45.0);
				this->motor.rijden(2000);
				this->handler.update();
				// Of is de lijn niet dik genoeg voor alle 3 en raakt
				//	alleen de achterste de lijn? (Referentie lijn)
			} else if (!sensoren[1]->zietLijn() && !sensoren[2]->zietLijn()
					&& sensoren[3]->zietLijn()) {
				this->motor.stoppen();
				gevonden = true;
				break;
			}
		}
	}
	return gevonden;
}

Motors Robot::getMotor() {
	return this->motor;
}


