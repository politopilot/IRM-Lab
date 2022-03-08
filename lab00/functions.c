// lab00, lab procedure, tasks 1 & 3

// source file

/* 
 * this file contains the implementation of the functions relevant for
 * lab00.
 * The declarations of the functions are in the corresponding header 
 * file (functions.h).
*/

// the header file needs to be included
#include "functions.h"

/* task 1
 * The function print_bits() accepts an input of type uint16_t 
 * (arg_word) and has no return value (void).
 * The function simply writes the binary and hexadecimal number of the
 * input to the terminal.
*/
void print_bits(uint16_t arg_word)
{
    // Print the number in hexadecimal format with at least 4 digits with leading zeroes
    char binary_string[] = "0000 0000 0000 0000";
    uint16_t arg_copy = arg_word;

    for (int i = 0; i < 19; i++)
    {
        int index = 18 - i;
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
    printf("hex: 0x%04x, bin: %s\n",arg_word,binary_string);
}

/* task 3
 * The function bit_merge() accepts two uint16_t as inputs (lsb and msb) 
 * and combines them to a uint32_t number by merging them.
 * The return value is a uint32_t number.
 */
 uint32_t bit_merge(uint16_t lsb, uint16_t msb)
 {
    uint32_t lsb_32 = lsb;
    uint32_t msb_32 = msb;
    uint32_t result;
    uint32_t msb_shifted;

    msb_shifted = msb_32 << 16;
    result = msb_shifted | lsb_32;

    //printf("bit_merge returns: 0x%04x", result);
	return result;
 }
