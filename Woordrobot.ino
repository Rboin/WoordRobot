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

	Servo myservo = Servo();
	myservo.attach(9);
	penDown(5, myservo);
	penUp(5, myservo);
}

void loop() {



//	Serial.print("Sensor 1: ");
//	motor->getSensor1()->printSerial();
//	Serial.print(", Sensor 2: ");
//	motor->getSensor2()->printSerial();
//	Serial.print(", Sensor 3: ");
//	motor->getSensor3()->printSerial();
//	Serial.println();
//	Serial.println("===================================================");
//	delay(2000);

//	motor->rijden(4000);
//	motor->achter(4000);
}



//void f() {
//	motor->rijden(3000);
//	motor->rechts(90.0);
//	motor->rijden(800);
//	motor->links(180.0);
//	motor->rijden(800);
//	motor->links(90.0);
//	motor->rijden(1000);
//	motor->links(90.0);
//	motor->rijden(500);
//	motor->links(180.0);
//	motor->rijden(500);
//	motor->links(90.0);
//	motor->rijden(4000);
//}
//
//void volgen(bool volgen) {
//	while(volgen) {
//		while(!motor->getSensor1()->zietLijn() && !motor->getSensor2()->zietLijn() && !motor->getSensor3()->zietLijn())
//			motor->rijden();
//		while(motor->getSensor1()->zietLijn() && !motor->getSensor2()->zietLijn() && motor->getSensor3()->zietLijn())
//			motor->links(5.0);
//		while (!motor->getSensor1()->zietLijn() && motor->getSensor2()->zietLijn() && motor->getSensor3()->zietLijn())
//			motor->rechts(5.0);
//		while(!motor->getSensor1()->zietLijn() && !motor->getSensor2()->zietLijn() /*&& motor->getSensor3()->zietLijn()*/)
//			motor->rijden(4000);
//	}
//}

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
