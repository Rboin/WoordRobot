#include "Motors.h"

//Pointer naar de Motors class
Motors * motor = new Motors();
//bool volgen = false;

void setup() {

	Serial.begin(9600);
//        motor->rijden(1000);
//	motor->rechts(360.0);
//	motor->links(90.0);
//	motor->rechts(180.0);
	motor->rechts(360.0);
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
