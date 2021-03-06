/*
 Motors.cpp
 WJT01
 */

#include "Motors.h"

Motors::Motors() {
	this->previousMillis = 0;
	pinMode(4, OUTPUT);
	pinMode(7, OUTPUT);

	// 1 graden is X aantal ms
	this->oneDegree = 20.3;

	// motoren
	this->snelheidMotorLinks = 160;
	this->snelheidMotorRechts = 170;
}

void Motors::rijden() {
	digitalWrite(4, HIGH);
	digitalWrite(7, HIGH);
	analogWrite(5, this->snelheidMotorLinks);
	analogWrite(6, this->snelheidMotorRechts);
}


void Motors::rijden(int tijd) {
	long currentMillis = millis();
	Serial.println("millis gedaan");
	this->previousMillis = currentMillis;
	while (currentMillis - this->previousMillis < tijd) {
		Serial.println("while");
		digitalWrite(4, HIGH);
		digitalWrite(7, HIGH);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
		currentMillis = millis();
	}
	Serial.println("na de while");
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::verandersnelheid(int delta) {
	this->snelheidMotorLinks += delta;
	this->snelheidMotorRechts += delta;
}

void Motors::links(int tijd) {
	long currentMillis = millis();
	this->previousMillis = currentMillis;
	while (currentMillis - this->previousMillis < tijd) {
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
	this->previousMillis = currentMillis;
	while (currentMillis - this->previousMillis < (degrees * this->oneDegree)) {
		digitalWrite(4, HIGH);
		digitalWrite(7, LOW);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
		currentMillis = millis();
	}
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::rechts(int tijd) {
	long currentMillis = millis();
	this->previousMillis = currentMillis;
	while (currentMillis - this->previousMillis < tijd) {
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
	this->previousMillis = currentMillis;
	while (currentMillis - this->previousMillis < (degrees * this->oneDegree)) {
		digitalWrite(4, LOW);
		digitalWrite(7, HIGH);

		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
		currentMillis = millis();
	}
	analogWrite(5, 0);
	analogWrite(6, 0);
	Serial.println("klaar!");
}

void Motors::achter(int tijd) {
	int oudeLinks = 205;
	int oudeRechts = 160;
	long currentMillis = millis();
	Serial.println("millis gedaan");
	this->previousMillis = currentMillis;
	while (currentMillis - this->previousMillis < tijd) {
		Serial.println("while");
		Serial.println(currentMillis);
		digitalWrite(4, LOW);
		digitalWrite(7, LOW);
		analogWrite(5, this->snelheidMotorLinks);
		analogWrite(6, this->snelheidMotorRechts);
		currentMillis = millis();
	}
	Serial.println("na de while");
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::achter() {
	digitalWrite(4, LOW);
	digitalWrite(7, LOW);
	analogWrite(5, this->snelheidMotorLinks);
	analogWrite(6, this->snelheidMotorRechts);
}

void Motors::stoppen() {
	analogWrite(5, 0);
	analogWrite(6, 0);
}
