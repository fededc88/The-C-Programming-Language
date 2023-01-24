/*
 * Exercise 2-7: Write a function invert(x,p,n) that returns x with the n bits
 * that begin at postion p inverted (i.e. 1 changed into 0 and vice versa),
 * leaving the others unchanged.
 *  
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */

#include "stdio.h"

unsigned invert(unsigned x, unsigned int p, unsigned int n);

/* invert: returns x with the n bits that begin at position p inverted */
unsigned invert(unsigned x, unsigned int p, unsigned int n)
{
    unsigned int mask;

    /*  mask to extract the n bits that begins at position p of x:
     * ~0 is all 1 bits, shifting it left n bit positions with ~0 << n places
     * zeros in the rightmost n bits, complementing with ~ makes the mask with
     * ones in the rightmost n bits.
     * << (p+1-n) shift 1s to p position.
     *
     */
    mask = (~(~0 << n)) << (p+1-n);

    return ( (x & ~mask) | (~x & mask) ); 
}

void main (void)
{

    printf("%#4x\n", (unsigned int) invert(0x3333, 11, 4));

}

// 
// End of file.
//

