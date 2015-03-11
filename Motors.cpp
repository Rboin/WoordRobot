/*
 Motors.cpp
 WJT01
 */

#include "Arduino.h"
#include "Motors.h"

Motors::Motors(int pot1, int pot2) {
//  _pot1 = pot1;
//  _pot2 = pot2;
//  pinMode(pot1, INPUT);
//  pinMode(pot2, INPUT);
	pinMode(4, OUTPUT);
	pinMode(7, OUTPUT);

	// 1 graden is X aantal ms
	oneDegree = 20.0694444444;
	//rechts (rood)
	snelheidMotorRechts = 190;
	//links (geel)
	snelheidMotorLinks = 170;
}

void Motors::rijden() {
	digitalWrite(4, HIGH);
	digitalWrite(7, HIGH);
	analogWrite(5, this->snelheidMotorRechts);
	analogWrite(6, this->snelheidMotorLinks);
}

void Motors::rijden(int tijd) {
	long currentMillis = millis();
	previousMillis = currentMillis;
	while (currentMillis - previousMillis > tijd) {
		digitalWrite(4, HIGH);
		digitalWrite(7, HIGH);
		analogWrite(5, this->snelheidMotorRechts);
		analogWrite(6, this->snelheidMotorLinks);
		currentMillis = millis();
	}
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::verandersnelheid(int delta) {
	this->snelheidMotorRechts += delta;
	this->snelheidMotorLinks += delta;
}

void Motors::links(int tijd) {
	digitalWrite(4, HIGH);
	digitalWrite(7, LOW);
	analogWrite(5, this->snelheidMotorRechts);
	analogWrite(6, this->snelheidMotorLinks);
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
	analogWrite(5, this->snelheidMotorRechts);
	analogWrite(6, this->snelheidMotorLinks);
	delay(degrees * this->oneDegree);
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::rechts(int tijd) {
	digitalWrite(4, LOW);
	digitalWrite(7, HIGH);
	analogWrite(5, this->snelheidMotorRechts);
	analogWrite(6, this->snelheidMotorLinks);
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
	analogWrite(5, this->snelheidMotorRechts);
	analogWrite(6, this->snelheidMotorLinks);
	delay(degrees * this->oneDegree);
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::achter(int tijd) {
	digitalWrite(4, LOW);
	digitalWrite(7, LOW);
	analogWrite(5, this->snelheidMotorRechts);
	analogWrite(6, this->snelheidMotorLinks);
	delay(tijd);
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::stoppen() {
	analogWrite(5, 0);
	analogWrite(6, 0);
}

//void Motors::printPotWaarde(int potmeter)
//{
//  Serial.println(map(analogRead(potmeter), 0, 1023, 0 ,255));
//}
