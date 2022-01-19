/*
 * Exercise 2-9: In a two's complement number system, x&= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount.
 *   
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */

#include "stdio.h"

unsigned bitcount(unsigned x);

/* bitcount: count 1 bits in x */
unsigned bitcount(unsigned x)
{
    unsigned int b;
/*
 * How x &= (x-1) funtion:
 *
 * When 0x01 is substracted to a number, i.e 0xFF, the least significant bit is
 * switched to 0.
 * 
 * 		0xFF - 0x01 = 0xFE 
 *
 * 		1111 1111 - 0000 0001 = 1111 1110
 *
 * However, if we substruct 0x01 to a number where the least significant bit is
 * 0 we borrow a bit from the next available 1-bit to left and invert the bits
 * to the right of the borrowed one. Notice here the 4 least significant bits of
 * 0xF8
 * 
 * 		0xF8 - 0x01 =  0xF7 
 *
 * 		1111 1000 - 0000 0001 = 11111  0111
 *
 * A bit-mask results of the (x-1) subtraction. When that mask is ANDed with the
 * original x value the rightmost 1-bit will be turned to 0, leaving the other
 * bits unchanged.
 * 
 *      0xF8 & 0xF7 = 0xF0
 *
 *      1111 1000 & 1111 0111 = 1111 0000
 *
 */
    for(b = 0; x != 0; x &= (x-1))
            b++;

    return b;
}

void main (void)
{

    printf("%d\n", (unsigned int) bitcount(0xCCFF88));

}

// 
// End of file.
//

