/*
 Motors.h
 WJT01
 */
#ifndef Motors_h
#define Motors_h

#include "Arduino.h"

class Motors {
private:
	int snelheidMotorLinks;
	int snelheidMotorRechts;
	double oneDegree;
	long previousMillis;
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
};

#endif
