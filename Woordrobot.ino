#include "Lijnsensor.h"
#include "Motors.h"


Motors motor(A0, A1);

void setup()
{
  motor.links(10000);
}

void loop()
{
}
