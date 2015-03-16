/*
 * Robot.h
 *
 *  Created on: Mar 12, 2015
 *      Author: Robin
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <Arduino.h>
#include <LedControl.h>
#include "Motors.h"
#include "Lijnsensor.h"

class Robot {
public:
	Robot(Lijnsensor *handler, int displayAddr);
	bool vindReferentieLijn();
	void initDisplay(bool b, int intensity);
	void setDisplay(int digit1, int digit2, char value1, char value2, bool dp, int time);
	Motors getMotor();
private:
	int displayAddr;
	Motors motor;
	Lijnsensor *handler;
	LedControl ledControl;
};



#endif /* ROBOT_H_ */
