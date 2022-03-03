// lab00, lap procedure, task 2

// source file for the program sum_numbers

/*
 * This file is used to generate an executable program that prints the 
 * sum of the two numbers in binary and hexadecimal format.
*/

// Since we will be using our own functions, we need to add the header
// file where the functions are declared.
// Keep in mind that the header file already includes standard libraries
// so they do not to be included here.
#include "functions.h"
 
 // main function
int main(int argc, char *argv[])
{

	//input two numbers
	uint16_t input1;
	uint16_t input2;
	scanf("%hx", &input1);
	scanf("%hx", &input2);
	printf("0x%04x 0x%04x\n", input1, input2);

	//check if numbers are 16bit numbers??? Handle overflow???

	//add and print
	uint16_t sum = input1 + input2;
	print_bits(sum);
	printf("\n");

	return 0;
}
