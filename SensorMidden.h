/*
 * SensorMidden.h
 *
 *  Created on: Mar 14, 2015
 *      Author: Robin
 */

#ifndef SENSORMIDDEN_H_
#define SENSORMIDDEN_H_

#include "SensorListener.h"
#include "Motors.h"
#include "Lijnsensor.h"

class SensorMidden: public SensorListener {
private:
	int pin;
	Motors motor;
public:
	SensorMidden(Lijnsensor sensor, Motors motor, int pin);
	bool zietLijn();
	int geefWaarde();
	void onDetect();
};


#endif /* SENSORMIDDEN_H_ */
