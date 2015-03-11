/*
 Motors.cpp
 WJT01
 */

#include "Motors.h"

Motors::Motors() {
//  _pot1 = pot1;
//  _pot2 = pot2;
//  pinMode(pot1, INPUT);
//  pinMode(pot2, INPUT);
	pinMode(4, OUTPUT);
	pinMode(7, OUTPUT);

	// 1 graden is X aantal ms
	oneDegree = 20.0694444444;

	// motoren
	snelheidMotorLinks = 190;

	snelheidMotorRechts = 170;

	s1 = new Lijnsensor(A0);

	s2 = new Lijnsensor(A1);
	s3 = new Lijnsensor(A2);
	// sensoren
}

void Motors::rijden() {
	digitalWrite(4, HIGH);
	digitalWrite(7, HIGH);
	analogWrite(5, this->snelheidMotorLinks);
	analogWrite(6, this->snelheidMotorRechts);
}

void Motors::rijden(int tijd) {
	int oudeLinks = 190;
	int oudeRechts = 170;
	long currentMillis = millis();
	previousMillis = currentMillis;
	while (currentMillis - previousMillis > tijd) {
		if (this->lijnGevonden())
			this->stoppen();

		digitalWrite(4, HIGH);
		digitalWrite(7, HIGH);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
		currentMillis = millis();
	}
	while (this->snelheidMotorLinks >= 100) {
		while (currentMillis - previousMillis > 50) {
			this->snelheidMotorLinks -= 10;
			this->snelheidMotorRechts -= 10;
			currentMillis = millis();
		}
	}
	this->snelheidMotorLinks = oudeLinks;
	this->snelheidMotorRechts = oudeRechts;
}

void Motors::verandersnelheid(int delta) {
	this->snelheidMotorLinks += delta;
	this->snelheidMotorRechts += delta;
}

void Motors::links(int tijd) {
	long currentMillis = millis();
	previousMillis = currentMillis;
	while (currentMillis - previousMillis > tijd) {
		digitalWrite(4, HIGH);
		digitalWrite(7, LOW);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
	}
}

/**
 * Dit is de functie om de robot een X aantal
 * graden naar links te laten draaien.
 * @param double degrees
 */
void Motors::links(double degrees) {
	long currentMillis = millis();
	previousMillis = currentMillis;
	while (currentMillis - previousMillis > (degrees * this->oneDegree)) {
		digitalWrite(4, HIGH);
		digitalWrite(7, LOW);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
	}
}

void Motors::rechts(int tijd) {
	long currentMillis = millis();
	previousMillis = currentMillis;
	while (currentMillis - previousMillis > tijd) {
		digitalWrite(4, LOW);
		digitalWrite(7, HIGH);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
	}
}

/**
 * Dit is de functie om de robot een X aantal
 * graden naar rechts te laten draaien.
 * @param double degrees
 */
void Motors::rechts(double degrees) {
	long currentMillis = millis();
	previousMillis = currentMillis;
	while (currentMillis - previousMillis > (degrees * this->oneDegree)) {
		digitalWrite(4, LOW);
		digitalWrite(7, HIGH);

		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
	}
}

void Motors::achter(int tijd) {
	int oudeLinks = 190;
	int oudeRechts = 170;
	long currentMillis = millis();
	previousMillis = currentMillis;
	while (currentMillis - previousMillis > tijd) {
		if (this->lijnGevonden())
			this->stoppen();

		digitalWrite(4, HIGH);
		digitalWrite(7, HIGH);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
		currentMillis = millis();
	}

	while (this->snelheidMotorLinks >= 100) {
		while (currentMillis - previousMillis > tijd) {
			this->snelheidMotorLinks -= 10;
			this->snelheidMotorRechts -= 10;
		}
	}
	this->snelheidMotorLinks = oudeLinks;
	this->snelheidMotorRechts = oudeRechts;
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::stoppen() {
	analogWrite(5, 0);
	analogWrite(6, 0);
}

bool Motors::lijnGevonden() {
	bool gevonden = false;
	if (this->s1->zietLijn())
		gevonden = true;
	if (this->s2->zietLijn())
		gevonden = true;
	if (this->s3->zietLijn())
		gevonden = true;
	return gevonden;
}

Lijnsensor* Motors::getSensor1() {
	return this->s1;
}
Lijnsensor* Motors::getSensor2() {
	return this->s2;
}
Lijnsensor* Motors::getSensor3() {
	return this->s3;
}

bool Motors::vindReferentieLijn() {
	bool gevonden = false;
	while (!gevonden) {
		// Robot ziet helemaal niks (startpunt)
		if (!this->s1->zietLijn() && !this->s2->zietLijn()
				&& !this->s3->zietLijn())
			this->rijden();
		// Robot zit op een lijn
		if (this->s1->zietLijn() && this->s2->zietLijn()) {
			// Robot rijdt over de lijn
			this->rijden();
			// Is de lijn dik genoeg voor alle 3 sensoren? (STOPLIJN)
			if (this->s1->zietLijn() && this->s2->zietLijn()
					&& this->s3->zietLijn()) {
				this->stoppen();
				this->links(90.0);
				// Of is de lijn niet dik genoeg voor alle 3 en raakt
				//	alleen de achterste de lijn? (Referentie lijn)
			} else if (!this->s1->zietLijn() && !this->s2->zietLijn()
					&& this->s3->zietLijn()) {
				this->stoppen();
				gevonden = true;
				break;
			}
		}
	}
	return gevonden;
}
