#include "hall_sensor.h"
#include <math.h>

//Function hall_sensor_get_field converts the measured voltage value to a magnetic field (in milli-tesla)
float hall_sensor_get_field(float voltage, float voltage_0)
{  
   float B;
   float sens = 0.05; // V/mT

   B = (voltage-voltage_0)/sens;

   return B;
}
