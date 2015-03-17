/*
 * Robot.cpp
 *
 *  Created on: Mar 12, 2015

 *      Author: Robin
 */

#include "Robot.h"

//LedControl wordt hier geinitialiseerd omdat hij anders de default constructor (LedControl::LedControl()) aanroept die niet bestaat
Robot::Robot(Lijnsensor *handler, Motors motor, int displayAddr) :
		ledControl(LedControl(12, 11, 10, 1)) {
	this->handler = handler;
	this->displayAddr = displayAddr;
	// Initialiseer de Motoren
	this->motor = motor;
	this->sensoren = this->handler->getSensoren();

}

bool Robot::vindReferentieLijn() {
	bool gevonden = false;
	bool collision = false;
	Serial.println("Handler");
	while (!gevonden) {
		this->motor.rijden();
		Serial.println("Ik ben vrolijk aan het rijden");
		if (sensoren[0]->zietLijn() && sensoren[1]->zietLijn() && !collision) {
			Serial.println("Sensor 0 en 1 zien een lijn");
			motor.stoppen();
			Serial.println("Motor is gestopt");
			if (!sensoren[2]->zietLijn()) {
				Serial.println("geen lijn");
				motor.rijden();
			}
			collision = true;
			Serial.println("Einde van de if, collision is true");
		}
		if (sensoren[0]->zietLijn() && sensoren[1]->zietLijn()
				&& sensoren[2]->zietLijn()) {
			motor.stoppen();
			motor.rechts(90.0);
			Serial.println("stoplijn tegengekomen");
		}
		if (sensoren[2]->zietLijn() && !sensoren[0]->zietLijn()
				&& !sensoren[1]->zietLijn()) {
			Serial.println("wel lijn");
			motor.stoppen();
			gevonden = true;
			Serial.println("gevonden");
		}
	}
	motor.stoppen();
	return gevonden;
}

bool Robot::vindEinde() {
	bool gevonden = false;
	bool collision = false;
	int cnt = 0;
	Serial.println("Handler");
	while (!gevonden) {
		this->motor.rijden();
		Serial.println("Ik ben vrolijk aan het rijden");
		if (sensoren[0]->zietLijn() && sensoren[1]->zietLijn() && !collision) {
			Serial.println("Sensor 0 en 1 zien een lijn");
			motor.stoppen();
			Serial.println("Motor is gestopt");
			if (!sensoren[2]->zietLijn()) {
				Serial.println("geen lijn");
				motor.rijden();
			}
			collision = true;
			Serial.println("Einde van de if, collision is true");
		}
		if (sensoren[0]->zietLijn() && sensoren[1]->zietLijn()
				&& sensoren[2]->zietLijn()) {
			motor.stoppen();
			motor.rechts(90.0);
			Serial.println("stoplijn tegengekomen");
			if(cnt ==1){
				gevonden = true;
				break;
			}
			cnt++;
		}
	}
	motor.stoppen();
	return gevonden;
}

void Robot::achterNaarLijn()
{
	Serial.println("functie lijnacher!");
	bool gevonden = false;
	while(!gevonden)
	{
		motor.achter();
		delay(10);
		Serial.println("na de while achter");
		if(sensoren[0]->zietLijn() && sensoren[1]->zietLijn())
		{
			Serial.println("gevonden");

			motor.stoppen();
			gevonden=true;
		}
	}

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
void Robot::setDisplay(int digit1, int digit2, char value1, char value2,
		bool dp, int time) {
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

