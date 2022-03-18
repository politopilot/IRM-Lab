#include "hall_sensor.h"
#include <math.h>

//Function hall_sensor_get_field converts the measured voltage value to a magnetic field (in milli-tesla)
float hall_sensor_get_field(float voltage, float voltage_0)
{  
   float D = 0.01; //in m
   float R = 0.02; //in m
   float n = 0.1;
   float B_r = 175.6;
   float B;

   // convert voltage into distance z
   float z;
   // 1/0.04m^n with mean voltage 1.6872V
   // 1/0.02m^n with mean voltage 2.3232V

   // Voltage = 1/z^n * m + voltage_0 
   // m = (2.3232-1.6872)/(1/0.02m^n - 1/0.04m^n)
   // slope m = 6.4224 [V*z^n]
   float m = 6.4224;

   // formula for z:

   z = pow((m/(voltage-voltage_0)),1/n); // in m

   float R2 = pow(R,2);
   float z2 = pow(z,2);
   float Dz2 = pow(D+z,2);

   B = (B_r/2) * ((D+z)/pow(R2 + Dz2, 0.5) - z/pow(R2 + z2,0.5));

   return B;
}
