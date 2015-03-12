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
	bool lijnGevonden();
	bool vindReferentieLijn();
	Lijnsensor* getSensor1();
	Lijnsensor* getSensor2();
	Lijnsensor* getSensor3();

//    void printPotWaarde(int potmeter);
private:
	int snelheidMotorLinks;
	int snelheidMotorRechts;
	double oneDegree;

	// Pointer variables naar de Lijnsensor class
	Lijnsensor *s1, *s2, *s3;
	long previousMillis = 0;
};

#endif
