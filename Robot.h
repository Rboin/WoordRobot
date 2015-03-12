/*
 * Robot.h
 *
 *  Created on: Mar 12, 2015
 *      Author: Robin
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <Arduino.h>
#include <Servo.h>
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
	void penDown(int stopTijd);
	void penUp(int stopTijd);
private:
	const int BENEDEN = 125;
	const int BOVEN = 25;
	Servo myservo;
	Motors motor;
	Lijnsensor s1, s2, s3;
};



#endif /* ROBOT_H_ */
