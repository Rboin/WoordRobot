/*
 * Robot.cpp
 *
 *  Created on: Mar 12, 2015

 *      Author: Robin
 */

#include "Robot.h"

Robot::Robot() {
	// Initialiseer de lijnsensoren
	s1 = Lijnsensor(A0);
	s2 = Lijnsensor(A1);
	s3 = Lijnsensor(A2);
	// Initialiseer de Motoren
	motor = Motors();
}

bool Robot::lijnGevonden() {
	bool gevonden = false;
	if (this->s1.zietLijn())
		gevonden = true;
	if (this->s2.zietLijn())
		gevonden = true;
	if (this->s3.zietLijn())
		gevonden = true;
	return gevonden;
}

bool Robot::vindReferentieLijn() {
	bool gevonden = false;
	while (!gevonden) {
		// Robot ziet helemaal niks (startpunt)
		if (!this->s1.zietLijn() && !this->s2.zietLijn()
				&& !this->s3.zietLijn())
			this->motor.rijden();
		// Robot zit op een lijn
		if (this->s1.zietLijn() && this->s2.zietLijn()) {
			// Robot rijdt over de lijn
			this->motor.rijden();
			// Is de lijn dik genoeg voor alle 3 sensoren? (STOPLIJN)
			if (this->s1.zietLijn() && this->s2.zietLijn()
					&& this->s3.zietLijn()) {
				this->motor.stoppen();
				this->motor.links(90.0);
				// Of is de lijn niet dik genoeg voor alle 3 en raakt
				//	alleen de achterste de lijn? (Referentie lijn)
			} else if (!this->s1.zietLijn() && !this->s2.zietLijn()
					&& this->s3.zietLijn()) {
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


