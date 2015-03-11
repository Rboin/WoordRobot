#include "Motors.h"

//Pointer naar de Motors class
Motors * motor = new Motors();
bool volgen = false;

void setup() {

	Serial.begin(9600);

}

void loop() {

	Serial.println("Sensor 1:");
	motor->getSensor1()->printSerial();
	Serial.println("Sensor 2:");
	motor->getSensor2()->printSerial();
	Serial.println("Sensor 3:");
	motor->getSensor3()->printSerial();
	delay(1000);

//	motor->rijden(4000);
//	motor->achter(4000);
}


//void volgLijn() {
//	/**
//	 * ----------------
//	 *    1      2
//	 *
//	 * 		 3
//	 * -----------------
//	 */
//	while (volgen) {
//		if (!sensor1.zietLijn() && !sensor2.zietLijn() && sensor3.zietLijn())
//			motor.rijden();
//		if (sensor1.zietLijn() && !sensor2.zietLijn() && sensor3.zietLijn())
//			motor.links(500);
////		while (sensor1.zietLijn() && !sensor2.zietLijn() && sensor3.zietLijn())
////			// moet nog naar deg
////			motor.rechts(1);
//		if (!sensor1.zietLijn() && sensor2.zietLijn() && sensor3.zietLijn()) {
//			motor.rechts(500);
////			while (!sensor1.zietLijn() && sensor2.zietLijn() && sensor3.zietLijn())
////				// moet nog naar deg
////				motor.rechts(1);
//		}
//	}
//}
//
