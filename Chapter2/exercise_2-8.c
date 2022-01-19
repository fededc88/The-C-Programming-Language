/*
 * Exercise 2-8: Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions.
 *  
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */

#include "stdio.h"

unsigned rightrot(unsigned x, unsigned int n);

/* rightrot: returns the value of the integer x rotated to the right n positions */
unsigned rightrot(unsigned x, unsigned int n)
{
    unsigned spare;
    unsigned int mask;
    unsigned int bits;
    unsigned int p;

    /*  mask to extract the n bits that begins at position p of x:
     * ~0 is all 1 bits, shifting it left n bit positions with ~0 << n places
     * zeros in the rightmost n bits, complementing with ~ makes the mask with
     * ones in the rightmost n bits.
     */
    mask = ~(~0 << n);

    /* extract bits to be rotated */
    bits = x & mask;

    /* count x integer lenght in bits */
    p = 0;
    spare = x;

    while(spare)
    {
        spare >>= 1;
        p++;
    }

    return ( (x >> n) | (bits << (p-n)) ); 
}

void main (void)
{

    printf("%#4X\n", (unsigned int) rightrot(0xCCFF88, 8));

}

// 
// End of file.
//

