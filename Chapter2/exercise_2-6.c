/*
 * Exercise 2-6: Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the
 * other bits unchanged.
 *  
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */

#include "stdio.h"

unsigned setbits(unsigned x, unsigned int p, unsigned int n, unsigned y);

/* setbits: returns x with the n bits that begin at position p set to the
            rightmost n bits of y, leaving the other bits unchanged */
unsigned setbits(unsigned x, unsigned int p, unsigned int n, unsigned y)
{
    unsigned int mask;

    /*  mask to extract the wightmost n bits of y:
     * ~0 is all 1 bits, shifting it left n bit positions with ~0 << n places
     * zeros in the rightmost n bits, complementing with ~ makes the mask with
     * ones in the rightmost n bits 
     */
    mask = ~(~0 << n);

    return ( (x & ~(mask << (p+1-n))) | ((y & mask) << (p+1-n)) );
}

void main (void)
{

    printf("%#4x\n", (unsigned int) setbits(0xFFFF, 7, 4, 0x000C));

}

// 
// End of file.
//

