#include "Motors.h"

//Pointer naar de Motors class
Motors * motor = new Motors();
bool volgen = false;

void setup() {





//	if (zoekReferentieLijn()) {
//
//	}

//	volgen = true;
//	volgLijn();
//	delay(1000);
//	volgen = false;
}

void loop() {
	motor->rijden(4000);
	motor->achter(4000);
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
//bool zoekReferentieLijn() {
//	bool gevonden = false;
//	while (!gevonden) {
//		// Robot ziet helemaal niks (startpunt)
//		if (!sensor1.zietLijn() && !sensor2.zietLijn() && !sensor3.zietLijn())
//			motor.rijden();
//		// Robot zit op een lijn
//		if (sensor1.zietLijn() && sensor2.zietLijn()) {
//			// Robot rijdt over de lijn
//			motor.rijden();
//			// Is de lijn dik genoeg voor alle 3 sensoren? (STOPLIJN)
//			if (sensor1.zietLijn() && sensor2.zietLijn()
//					&& sensor3.zietLijn()) {
//				motor.stoppen();
//				motor.links(500);
//				// Of is de lijn niet dik genoeg voor alle 3 en raakt
//				//	alleen de achterste de lijn? (Referentie lijn)
//			} else if (!sensor1.zietLijn() && !sensor2.zietLijn()
//					&& sensor3.zietLijn()) {
//				motor.stoppen();
//				gevonden = true;
//				break;
//			}
//		}
//	}
//
//	return gevonden;
//}
