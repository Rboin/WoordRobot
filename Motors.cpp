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
	snelheidmotor1 = 160;
	snelheidmotor2 = 170;
}

void Motors::rijden() {
	digitalWrite(4, HIGH);
	digitalWrite(7, HIGH);
	analogWrite(5, this->snelheidmotor1);
	analogWrite(6, this->snelheidmotor2);
}

void Motors::rijden(int tijd) {
	digitalWrite(4, HIGH);
	digitalWrite(7, HIGH);
	analogWrite(5, this->snelheidmotor1);
	analogWrite(6, this->snelheidmotor2);
	delay(tijd);
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::verandersnelheid(int delta) {
	this->snelheidmotor1 += delta;
	this->snelheidmotor2 += delta;
}

void Motors::links(int tijd) {
	digitalWrite(4, HIGH);
	digitalWrite(7, LOW);
	analogWrite(5, this->snelheidmotor1);
	analogWrite(6, this->snelheidmotor2);
	delay(tijd);
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::rechts(int tijd) {
	digitalWrite(4, LOW);
	digitalWrite(7, HIGH);
	analogWrite(5, this->snelheidmotor1);
	analogWrite(6, this->snelheidmotor2);
	delay(tijd);
	analogWrite(5, 0);
	analogWrite(6, 0);
}

void Motors::achter(int tijd) {
	digitalWrite(4, LOW);
	digitalWrite(7, LOW);
	analogWrite(5, this->snelheidmotor1);
	analogWrite(6, this->snelheidmotor2);
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
