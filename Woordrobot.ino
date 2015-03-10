#include "Lijnsensor.h"
#include "Motors.h"


Motors motor(A0, A1);
Lijnsensor sensor1(A0);
Lijnsensor sensor2(A1);
Lijnsensor sensor3(A2);


void setup()
{
  motor.rijden(10000);
}

void loop()
{
}
