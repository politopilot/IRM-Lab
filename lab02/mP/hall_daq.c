#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "feather_serial.h"
#include "hall_sensor.h"

// include your function definitions here



int main()
{
    // initialize all parameters
    int n;
    int16_t pin_reading;
    float volt;
    float quis_volt = 1.4406; // in V: measured ba taking the magnet away

    // char buffer
    char buf[4];

    // initialize the serial port on the port /dev/ttyUSB0, with baud rate 115200
    int fd = serialport_init( "/dev/ttyUSB0", 115200);

/*
    for(int i = 0; i < 50; i++){

        // write to the serial port to get a value
        char arg = '0';
        n = serialport_write(fd,((char*)&arg));
        if(n == -1 )
            printf("Unable to write the port\n");
        
        // Read the sensor value into the buffer from the serial port
        n = serialport_read(fd, buf, 4, 500);
        if(n == -1 )
            printf("Unable to read the port \n");

        // Convert the sensor value to a voltage
        pin_reading = atoi(buf); // cast to integer
        volt =  3.3 * (float)pin_reading / 4095;

        printf("%f\n", volt);      
        // Convert the voltage value to magnetic field
        float B = hall_sensor_get_field(volt, quis_volt);
        printf("%f mT\n",B);

    }*/

    char user_input = '1';
    int d = 40;
     int step_size = 2;

   do {
        user_input = getchar();
        if (user_input != '\n' && user_input != '0') {





    // write to the serial port to get a value
    char arg = '0';
    n = serialport_write(fd,((char*)&arg));
    if(n == -1 )
        printf("Unable to write the port\n");
    
    // Read the sensor value into the buffer from the serial port
    n = serialport_read(fd, buf, 4, 500);
    if(n == -1 )
        printf("Unable to read the port \n");

    // Convert the sensor value to a voltage
    pin_reading = atoi(buf); // cast to integer
    volt =  3.3 * (float)pin_reading / 4095;

    //printf("%f\n", volt);      
    // Convert the voltage value to magnetic field
    float B = hall_sensor_get_field(volt, quis_volt);
    printf("%d\t",d);
    printf("%f\n",B); //mT
    fprintf( stderr, "%d\t%f\n", d, B);

    d -= step_size;
      }
}
while (user_input != '0');
// Close the serial port
    serialport_close(fd);
    return 0;

}
