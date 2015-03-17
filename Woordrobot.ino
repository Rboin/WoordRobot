#include <LedControl.h>

#include <Servo.h>
#include "Robot.h"
#include "Motors.h"
#include "Lijnsensor.h"
#include "SensorLinks.h"
#include "SensorRechts.h"
#include "SensorMidden.h"

Lijnsensor *handler = new Lijnsensor();
Motors motor = Motors();
SensorLinks *links = new SensorLinks(handler, motor, A2);
SensorRechts *rechts = new SensorRechts(handler, motor, A0);
SensorMidden *midden = new SensorMidden(handler, motor, A1);
Robot *robot = new Robot(handler, motor, 0);
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
  Serial.println("gevonden");

  myservo.attach(9);
  penDown(5, myservo);
  penUp(5, myservo);

  motor.links(180.0);
  robot->achterNaarLijn();
  motor.rijden(3000);

  penDown(5, myservo);
  //	Serial.begin(9600);
  W();
  // 90.0 graden naar rechts is ons eindpunt
  penUp(5, myservo);
  motor.rijden(600);
  motor.links(90.0);


  T();
  // eind punt is naar beneden gericht
  motor.links(90.0);
  motor.rijden(300);
  motor.links(130.0);
  motor.rijden(90);

  J();
  // eind punt staat naar rechts
  motor.rijden(900);
  motor.links(120.0);

  O();
  // eind punt staat naar rechts
  motor.rijden(500);
  motor.links(90.0);

  I();
  penUp(5, myservo);
  robot->vindEinde();


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
	robot->setDisplay(1, 0, 'l', '1', false, 1000);
  motor.rijden(1500);
  penUp(5, myservo);

  motor.rechts(180.0);
  penDown(5, myservo);
  motor.rijden(1500);
  motor.links(90.0);

  motor.rijden(600);
  motor.links(90.0);
  motor.rijden(600);

  penUp(5, myservo);
  motor.achter(600);

  penDown(5, myservo);
  motor.rechts(90.0);
  motor.rijden(600);
  motor.links(90.0);
  motor.rijden(1500);

  penUp(5, myservo);
  motor.achter(1500);

  motor.rechts(90.0);
  //EIND
}

void T() {
	robot->setDisplay(1, 0, 'l', '2', false, 1000);
  penDown(5, myservo);
  motor.rijden(1500);
  motor.links(90.0);
  motor.rijden(600);

  penDown(5, myservo);
  motor.achter(1200);

  penUp(5, myservo);
  motor.links(90.0);
  motor.rijden(1000);
  //EIND
}

void J() {
	  robot->setDisplay(1, 0, 'l', '3', false, 1000);

  motor.rechts(90.0);

  penDown(5, myservo);
  motor.rijden(900);
  motor.links(90.0);
  motor.rijden(1500);

  penUp(5, myservo);
  motor.achter(1100);
  motor.rechts(90.0);
  //EIND
}

void O() {
	  robot->setDisplay(1, 0, 'l', '4', false, 1000);

  penDown(5, myservo);
  motor.rijden(1000);
  motor.rechts(90.0);
  motor.rijden(600);
  motor.rechts(90.0);
  motor.rijden(1000);
  motor.rechts(90.0);
  motor.rijden(600);
  penUp(5, myservo);

  motor.achter(1000);
  motor.rechts(180.0);
  //EIND
}

void I() {
	  robot->setDisplay(1, 0, 'l', '5', false, 1000);

  penDown(5, myservo);
  motor.rijden(1200);
  //EIND
}
