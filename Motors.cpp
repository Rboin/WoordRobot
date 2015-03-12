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
	oneDegree = 19.722222222;

	// motoren
	snelheidMotorLinks = 185;

	snelheidMotorRechts = 170;
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
	while (currentMillis - previousMillis < tijd) {
		Serial.println(currentMillis - previousMillis);

		digitalWrite(4, HIGH);
		digitalWrite(7, HIGH);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
		currentMillis = millis();
	}
	previousMillis = currentMillis;
	Serial.println("uit de eerste while");
	while (this->snelheidMotorLinks >= 100) {
		while (currentMillis - previousMillis < 50) {
			this->snelheidMotorLinks -= 10;
			this->snelheidMotorRechts -= 10;
			currentMillis = millis();
		}
	}
	Serial.println("Uit de tweede while");
	analogWrite(5, 0);
	analogWrite(6, 0);
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
	while (currentMillis - previousMillis < tijd) {
		digitalWrite(4, HIGH);
		digitalWrite(7, LOW);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
	}
	analogWrite(5, 0);
	analogWrite(6, 0);
}

/**
 * Dit is de functie om de robot een X aantal
 * graden naar links te laten draaien.
 * @param double degrees
 */
void Motors::links(double degrees) {
	Serial.println("links");
	long currentMillis = millis();
	previousMillis = currentMillis;
	while (currentMillis - previousMillis < (degrees * this->oneDegree)) {
		digitalWrite(4, HIGH);
		digitalWrite(7, LOW);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
		currentMillis = millis();
//		delay(degrees*this->oneDegree);
	}
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::rechts(int tijd) {
	long currentMillis = millis();
	previousMillis = currentMillis;
	while (currentMillis - previousMillis < tijd) {
		digitalWrite(4, LOW);
		digitalWrite(7, HIGH);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
		currentMillis = millis();
	}
	analogWrite(5, 0);
	analogWrite(6, 0);
}

/**
 * Dit is de functie om de robot een X aantal
 * graden naar rechts te laten draaien.
 * @param double degrees
 */
void Motors::rechts(double degrees) {
	Serial.println("rechts");
	long currentMillis = millis();
	previousMillis = currentMillis;
	while (currentMillis - previousMillis < (degrees * this->oneDegree)) {
		digitalWrite(4, LOW);
		digitalWrite(7, HIGH);

		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
		currentMillis = millis();
//		delay(degrees*this->oneDegree);
	}
	analogWrite(5, 0);
	analogWrite(6, 0);
	Serial.println("klaar!");
}

void Motors::achter(int tijd) {
	int oudeLinks = 190;
	int oudeRechts = 170;
	long currentMillis = millis();
	previousMillis = currentMillis;
	while (currentMillis - previousMillis < tijd) {
		digitalWrite(4, HIGH);
		digitalWrite(7, HIGH);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
		currentMillis = millis();
	}
	previousMillis = currentMillis;
	while (this->snelheidMotorLinks >= 100) {
		while (currentMillis - previousMillis < tijd) {
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
