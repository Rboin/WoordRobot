/*
 Motors.h
 WJT01
 */
#ifndef Motors_h
#define Motors_h

#include "Arduino.h"
#include "Lijnsensor.h"

class Motors {
public:
	Motors();

	void rijden();
	void rijden(int tijd);
	void verandersnelheid(int delta);
	void links(int tijd);
	void links(double degrees);
	void rechts(int tijd);
	void rechts(double degrees);
	void achter(int tijd);
	void stoppen();

//    void printPotWaarde(int potmeter);
private:
	int snelheidMotorLinks;
	int snelheidMotorRechts;
	double oneDegree;
	long previousMillis = 0;
};

#endif
