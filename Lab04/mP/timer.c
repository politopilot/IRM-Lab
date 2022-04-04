#include "feather_serial.h"

/* These are system level includes */
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

void delay(int number_of_seconds)
{
    int micro_seconds = 1000000 * number_of_seconds; // convert to microseconds
  
    clock_t start_time = clock(); // set start_time to current time
  
    while (clock() < start_time + micro_seconds); //does nothing for x microseconds: it compares...
}


int main()
{   // Intialize serial port and variables
    int fd = serialport_init( "/dev/ttyUSB0", 115200);
    
    int correct_input_value = 0; // "boolean" value that switches to 1 when a suitable input has been received
    int run_time;               // Amount of seconds the timer is supposed to run
    int i;                       // Iteration variable

    char* reset = "a";           // Character to be sent through the serial port to reset the servo to its 0° position.
    char* increase = "b";        // Character to be sent through the serial port to tell the Arduino to advance by 1 second.
    


    // loop until the user wants to quit the timer program
    while (1) {
    

        /*_________________Begin - Input Section_________________*/
        correct_input_value = 1;
        printf("please enter a number between 0 and 150 to start the timer\n");
        printf("enter anything else to stop the program\n");
        
        char input[3];
        scanf("%3s",input);

        run_time = atoi(input);
        if (run_time == 0) {
            if (input[0] != 48)
                correct_input_value = 0;
        }

        if(run_time > 150 || run_time < 0)
            correct_input_value = 0;

        if (!correct_input_value) {
            printf("Exiting...\n" );
            break;
            
        }



        
        
        /*_________________End - Input Section_________________*/

		
        
        
        /*_________________Begin - Reset Section_________________*/
        char arg = 'a';
        int n = serialport_writebyte(fd,((char*)&arg));
        if(n == -1 )
            printf("Unable to write the port \n");
        
        /*_________________End - Reset Section_________________*/
        
        
        
		delay(1); // Wait a second before starting the timer
        printf("%d seconds will be timed, starting now! \n", run_time);
        
        
        /*_________________Begin - Advance Section_________________*/
        int seconds_passed = 0;
        while (seconds_passed < run_time) {

        
        arg = 'b';
        n = serialport_writebyte(fd,((char*)&arg));
        if(n == -1 )
            printf("Unable to write the port \n");
        seconds_passed += 1;
        delay(1);
    }
        
        /*_________________End - Advance Section_________________*/
    }
    
    // Close the serial port
	serialport_close(fd);
    
	return 0;
    
}
