/*
  Motors.h
  WJT01
*/
#ifndef Motors_h
#define Motors_h

#include "Arduino.h"

class Motors
{
  public:
    Motors(int pot1,int pot2);
    void rijden();
    void rijden(int tijd);
    void verandersnelheid(int delta);
    void links(int tijd);
    void links(double degrees);
    void rechts(int tijd);
    void rechts(double degrees);
    void achter(int tijd);
    void stoppen();
//    void printPotWaarde(int potmeter);
  private:
//    int _pot1;
//    int _pot2;
    int snelheidMotorLinkss;
    int snelheidMotorLinks;
    double oneDegree;
};

#endif
