/*
 Lijnsensor.h
 WJT01
 */
#ifndef Lijnsensor_h
#define Lijnsensor_h

#include <stdlib.h>
#include "Arduino.h"
#include "SensorListener.h"
//#include "Motors.h"

class Lijnsensor {
private:
	SensorListener *sensoren[3];
public:
	Lijnsensor(){};
	void attachSensor(SensorListener *listener, int index);
	SensorListener **getSensoren();
	void update();
};

#endif
