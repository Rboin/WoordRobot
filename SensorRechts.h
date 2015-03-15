/*
 * SensorRechts.h
 *
 *  Created on: Mar 14, 2015
 *      Author: Robin
 */

#ifndef SENSORRECHTS_H_
#define SENSORRECHTS_H_

#include "SensorListener.h"
#include "Motors.h"
#include "Lijnsensor.h"

class SensorRechts: public SensorListener {
private:
	int pin;
	Motors motor;
public:
	SensorRechts(Lijnsensor sensor, Motors motor, int pin);
	bool zietLijn();
	int geefWaarde();
	void onDetect();
};


#endif /* SENSORRECHTS_H_ */
