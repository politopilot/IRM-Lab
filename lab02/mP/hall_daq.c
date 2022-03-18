#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "feather_serial.h"

// include your function definitions here



int main()
{
    // initialize all parameters
    int n;
    int16_t pin_reading;
    float volt;

    // char buffer
    char buf[4];

    // initialize the serial port on the port /dev/ttyUSB0, with baud rate 115200
    int fd = serialport_init( "/dev/ttyUSB0", 115200);


    for(int i = 0; i < 50; i++){

        // write to the serial port to get a value
        char arg = '0';
        n = serialport_write(fd,((char*)&arg));
        if(n == -1 )
            printf("Unable to write the port\n");
        
        // Let the user know if you were able to write to the port



        // Read the sensor value into the buffer from the serial port
        n = serialport_read(fd, buf, 4, 500);
        if(n == -1 )
            printf("Unable to read the port \n");
        
        // Let the user know if you were able to read from the port


        // Convert the sensor value to a voltage
        pin_reading = atoi(buf); // cast to integer
        volt =  3.3 * (float)pin_reading / 4095;

        /*for(int u = 0; u < 4; u++){
            printf("%d ", buf[u]);
        }*/

        //printf("pinreading: %d\n",pin_reading);
        //printf("volt:%f\n", volt);

        printf("%f\n", volt);
        
    }

	// Convert the voltage value to magnetic field
    


    // Close the serial port
    serialport_close(fd);
	return 0;

}
