/*
  Motors.cpp
  WJT01
*/

#include "Arduino.h"
#include "Motors.h"

Motors::Motors(int pot1, int pot2)
{
  _pot1 = pot1;
  _pot2 = pot2;
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
}

void Motors::rijden(int tijd)
{    
  digitalWrite(4,HIGH);  
  digitalWrite(7,HIGH);   
  analogWrite(5, map(analogRead(_pot1), 0, 1023, 0 ,255));
  analogWrite(6, map(analogRead(_pot2), 0, 1023, 0 ,255));
  delay(tijd);
  analogWrite(5, 0);
  analogWrite(6, 0);
}
    
void Motors::verandersnelheid(int delta)
{
}

void Motors::links(int tijd)
{
}
    
void Motors::rechts(int tijd)
{
}

void Motors::achter(int tijd)
{
}

void Motors::stoppen()
{
}

int Motors::geefPotWaarde(int potmeter)
{
}
