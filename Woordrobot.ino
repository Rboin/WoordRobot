#include <Servo.h>
#include "Robot.h"
#include "Motors.h"
#include "Lijnsensor.h"
#include "SensorLinks.h"
#include "SensorRechts.h"
#include "SensorMidden.h"

Lijnsensor *handler = new Lijnsensor();
Motors motor = Motors();
SensorLinks *links = new SensorLinks(handler, motor, A1);
SensorRechts *rechts = new SensorRechts(handler, motor, A2);
SensorMidden *midden= new SensorMidden(handler, motor, A3);
Robot *robot = new Robot(handler, 0);
Servo myservo = Servo();

void setup() {
	Serial.begin(9600);

	robot->initDisplay(false, 8);
	// Voorbeeld hoe je kan werken met de display
	robot->setDisplay(1, 0, 'l', '1', false, 1000);
	robot->setDisplay(1, 0, 'l', '2', false, 1000);

	//Sensoren
	Serial.println("In Setup");
	robot->vindReferentieLijn();

//	Serial.begin(9600);

	myservo.attach(9);
	penDown(5, myservo);
	penUp(5, myservo);
}

void loop() {

}

void penDown(int stopTijd, Servo myservo) {
	for (int i = 25; i < 125; i++) {
		myservo.write(i);

		delay(stopTijd);
	}
}

void penUp(int stopTijd, Servo myservo) {
	for (int i = 125; i > 25; i--) {
		myservo.write(i);
		delay(stopTijd);
	}
}

//hoogte: 5000
//breedte: 2500

void W() {
	penDown(5, myservo);
	motor.rijden(5000);
	penUp(5, myservo);

	motor.rechts(180.0);
	motor.rijden(5000);
	motor.links(90.0);

	penDown(5, myservo);
	motor.rijden(1250);
	motor.links(90.0);
	motor.rijden(1250);

	penUp(5, myservo);
	motor.rechts(180.0);
	motor.rijden(1250);

	penDown(5, myservo);
	motor.links(90.0);
	motor.rijden(1250);
	motor.links(90.0);
	motor.rijden(5000);

	penUp(5, myservo);
	motor.links(180.0);
	motor.rijden(5000);
	//EIND
}

void T() {
	penDown(5, myservo);
	motor.rijden(5000);
	motor.links(90.0);
	motor.rijden(1250);

	penUp(5, myservo);
	motor.links(180.0);

	penDown(5, myservo);
	motor.rijden(2500);

	penUp(5, myservo);
	motor.links(180.0);
	motor.rijden(1250);
	motor.links(90.0);
	motor.rijden(5000);
	//EIND
}

void J() {
	motor.rechts(90.0);

	penDown(5, myservo);
	motor.rijden(2500);
	motor.links(90.0);
	motor.rijden(5000);

	penUp(5, myservo);
	motor.links(180.0);
	motor.rijden(5000);
	//EIND
}

void O() {
	penDown(5, myservo);
	motor.rijden(5000);
	motor.rechts(90.0);
	motor.rijden(2500);
	motor.rechts(90.0);
	motor.rijden(5000);
	motor.rechts(90.0);
	motor.rechts(2500);
	penUp(5, myservo);

	motor.rechts(180.0);
	motor.rijden(2500);
	//EIND
}

void I() {
	motor.rechts(90.0);
	penDown(5, myservo);
	motor.rijden(2500);

	penUp(5, myservo);
	motor.rechts(180.0);
	motor.rijden(1250);
	motor.rechts(90.0);

	penDown(5, myservo);
	motor.rijden(5000);
	motor.links(90.0);
	motor.rijden(1000);

	penUp(5, myservo);
	motor.rechts(180.0);
	motor.rijden(1000);
	motor.rechts(90.0);
	motor.rijden(5000);
	motor.links(90.0);
	motor.rijden(1250);
	//EIND
}
