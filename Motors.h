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
    void rijden(int tijd);
    void verandersnelheid(int delta);
    void links(int tijd);
    void rechts(int tijd);
    void achter(int tijd);
    void stoppen();
    int geefPotWaarde(int potmeter);
  private:
    int _pot1;
    int _pot2;
};

#endif
