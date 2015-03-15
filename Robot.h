/*
 * Robot.h
 *
 *  Created on: Mar 12, 2015
 *      Author: Robin
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <Arduino.h>
#include "Motors.h"
#include "Lijnsensor.h"

class Robot {
public:
	Robot(Lijnsensor handler);
	bool vindReferentieLijn();
	Motors getMotor();
private:
	Motors motor;
	Lijnsensor handler;
};



#endif /* ROBOT_H_ */
