/*
 * Robot.h
 *
 *  Created on: Mar 12, 2015
 *      Author: Robin
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <Arduino.h>
#include "Lijnsensor.h"
#include "Motors.h"

class Robot {
public:
	Robot();
	bool lijnGevonden();
	bool vindReferentieLijn();
	Lijnsensor getSensor1();
	Lijnsensor getSensor2();
	Lijnsensor getSensor3();
	Motors getMotor();
private:
	Motors motor;
	Lijnsensor s1, s2, s3;
};



#endif /* ROBOT_H_ */
