// lab00, lab procesure, task 4

// source file for the program manipulate_two_numbers

/*
 * This file is used to generate an executable program that reads two
 * numbers from the terminal and output the merged result in 
 * hexadecimal, and the sum in hexadecimal and binary format.
*/

// again, the header of our function library is already included 
#include "functions.h"

// main
int main(int argc, char *argv[])
{
	// ***** enter your code here ***** //
	/*
	merging 0x1234 and 0x2343 results in 0x23431234
	the sum is hex: 0x3577, bin: 0011 0101 0111 0111
	*/
	// scan the terminal for inputs from the user
	printf("Enter zero twice to exit the code. i.e. 0 0\n");




	while(1){
		printf("Please enter two numbers\n");

		//input two numbers
		uint16_t input1;
		uint16_t input2;
		scanf("%hx", &input1);
		scanf("%hx", &input2);
		
		//Check for exit condition
		if((input1 == 0) && (input2 == 0)){
			break;
		}



		// use the function bit_merge() to merge the numbers
		uint32_t merge = bit_merge(input1, input2);
		printf("\n");
		
		// use the function print_bits to print the sum to the terminal
		uint16_t sum = input1 + input2;

		printf("merging 0x%04x and 0x%04x results in 0x%08x\n", input1, input2, merge);
		printf("\tthe sum is ");
		print_bits(sum);

		printf("\n");
	}
	
	// ***** end of your code ***** //

	return 0;
}
