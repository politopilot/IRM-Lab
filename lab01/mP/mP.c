#include <stdio.h>
#include <stdint.h>
#include "feather_serial.h"


// ***** print_bits() can be implemented here ***** //
		

uint8_t print_bits(uint8_t num1, uint8_t num2) //sums up two numbers and prints them in binary
{
		uint16_t arg_word = num1 + num2;

    // Print the number in hexadecimal format with at least 4 digits with leading zeroes
    char binary_string[] = "0000 0000";
    uint8_t arg_copy = (uint8_t)arg_word;

    for (int i = 0; i < 9; i++)
    {
        int index = 8 - i;
        if (binary_string[index] != ' ') {


            if (arg_copy & 1) {
                binary_string[index] = '1';
            } else {
                binary_string[index] = '0';
            }
        arg_copy >>= 1;
        }
        
        index -= 1;

    }
    printf("bin: %s\n", binary_string);

    return((uint8_t)arg_word);


}

			
// *********************************************** //

int32_t main()
{
  int n;
  // initialization of serial communication, port and baud rate are specified
  int fd = serialport_init( "/dev/ttyUSB0", 115200);
  uint8_t arg = (uint8_t)245;
  
  while(1)
  {
		// ***** your code goes here ***** //

		printf("Please enter two numbers\n");
		printf("Exit condition: 0 0\n");

		//input two numbers
		uint16_t input1;
		uint16_t input2;
		scanf("%hd", &input1);
		scanf("%hd", &input2);


		//Check for exit condition
		if((input1 == 0) && (input2 == 0)){
			break;
		}

		arg = print_bits((uint8_t)input1, (uint8_t)input2);

		
		// ******************************* //
		
		// send arg via serial communication to the mC
		// type casting is again needed to match type
		n = serialport_writebyte(fd,((char*)&arg));
		if(n == -1 )
			printf("Unable to write the port \n");
  }
  
  // close serial communication
  serialport_close(fd);
  return 0;
}

