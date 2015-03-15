/*
 * SensorListener.h
 *
 *  Created on: Mar 13, 2015
 *      Author: Robin
 */

#ifndef SENSORLISTENER_H_
#define SENSORLISTENER_H_

class SensorListener {
public:
	SensorListener(){}
	virtual ~SensorListener(){}
	virtual bool zietLijn() = 0;
	virtual int geefWaarde() = 0;
	virtual void onDetect() = 0;
};


#endif /* SENSORLISTENER_H_ */
