#include "Lijnsensor.h"
#include "Motors.h"

Motors motor(A0, A1);
Lijnsensor sensor1(A0);
Lijnsensor sensor2(A1);
Lijnsensor sensor3(A2);
bool volgen = false;

void setup() {
	motor.links(10000);
//	if (zoekReferentieLijn()) {
//
//	}

	volgen = true;
	volgLijn();
	delay(1000);
	volgen = false;
}

void loop() {
}

void volgLijn() {
	/**
	 * ----------------
	 *    1      2
	 *
	 * 		 3
	 * -----------------
	 */
	while (volgen) {
		if (!sensor1.zietLijn() && !sensor2.zietLijn() && sensor3.zietLijn())
			motor.rijden();
		if (sensor1.zietLijn() && !sensor2.zietLijn() && sensor3.zietLijn())
			motor.links(500);
		if (!sensor1.zietLijn() && sensor2.zietLijn() && sensor3.zietLijn())
			motor.rechts(500);
	}
}

//bool zoekReferentieLijn() {
//	bool gevonden = false;
//	while (true) {
//		// Robot ziet helemaal niks (startpunt)
//		if (!sensor1.zietLijn() && !sensor2.zietLijn() && !sensor3.zietLijn())
//			motor.rijden();
//
//		// Robot heeft een lijn gevonden en draait naar links
//		if (sensor1.zietLijn() && sensor2.zietLijn() && !sensor3.zietLijn()) {
//			motor.stoppen();
//			motor.links(500);
//		}
//
//		if (!sensor1.zietLijn() && !sensor2.zietLijn() && sensor3.zietLijn()) {
//			motor.rijden(1000);
//			gevonden = true;
//			break;
//		}
//		// Robot zit op een dikke lijn
//		if (sensor1.zietLijn() && sensor2.zietLijn() && sensor3.zietLijn()) {
//			motor.stoppen();
//		}
//	}
//
//	return gevonden;
//}
