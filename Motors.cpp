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
		this->snelheidMotorLinks -= 10;
		this->snelheidMotorRechts -= 10;
		delay(50);
	}
	this->snelheidMotorLinks = oudeLinks;
	this->snelheidMotorRechts = oudeRechts;
//	analogWrite(5, 0);
//	analogWrite(6, 0);
}

void Motors::verandersnelheid(int delta) {
	this->snelheidMotorLinks += delta;
	this->snelheidMotorRechts += delta;
}

void Motors::links(int tijd) {
	digitalWrite(4, HIGH);
	digitalWrite(7, LOW);
	analogWrite(5, this->snelheidMotorLinks);
	analogWrite(6, this->snelheidMotorRechts);
	delay(tijd);
	analogWrite(5, 0);
	analogWrite(6, 0);
}

/**
 * Dit is de functie om de robot een X aantal
 * graden naar links te laten draaien.
 * @param double degrees
 */
void Motors::links(double degrees) {
	digitalWrite(4, HIGH);
	digitalWrite(7, LOW);
	analogWrite(5, this->snelheidMotorLinks);
	analogWrite(6, this->snelheidMotorRechts);
	delay(degrees * this->oneDegree);
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::rechts(int tijd) {
	digitalWrite(4, LOW);
	digitalWrite(7, HIGH);
	analogWrite(5, this->snelheidMotorLinks);
	analogWrite(6, this->snelheidMotorRechts);
	delay(tijd);
	analogWrite(5, 0);
	analogWrite(6, 0);
}

/**
 * Dit is de functie om de robot een X aantal
 * graden naar rechts te laten draaien.
 * @param double degrees
 */
void Motors::rechts(double degrees) {
	digitalWrite(4, LOW);
	digitalWrite(7, HIGH);
	analogWrite(5, this->snelheidMotorLinks);
	analogWrite(6, this->snelheidMotorRechts);
	delay(degrees * this->oneDegree);
	analogWrite(5, 0);
	analogWrite(6, 0);
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
		this->snelheidMotorLinks -= 10;
		this->snelheidMotorRechts -= 10;
		delay(50);
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

//void Motors::printPotWaarde(int potmeter)
//{
//  Serial.println(map(analogRead(potmeter), 0, 1023, 0 ,255));
//}
