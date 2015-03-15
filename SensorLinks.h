/*
 * SensorLinks.h
 *
 *  Created on: Mar 14, 2015
 *      Author: Robin
 */

#ifndef SENSORLINKS_H_
#define SENSORLINKS_H_

#include "SensorListener.h"
#include "Motors.h"
#include "Lijnsensor.h"

class SensorLinks: public SensorListener {
private:
	int pin;
	Motors motor;
public:
	SensorLinks(Lijnsensor sensor, Motors motor, int pin);
	bool zietLijn();
	int geefWaarde();
	void onDetect();
};



#endif /* SENSORLINKS_H_ */
