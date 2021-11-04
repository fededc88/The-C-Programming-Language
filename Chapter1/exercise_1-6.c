/*
 * Exercise 1-6. Verify that the expresion getchar() != EOF is 0 or 1
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kinrdg of submision are welcome. 
 */
  
#include <stdio.h>

void main (void)
{
/*
 * NOTE: getchar() != EOF equals 1 only if input char is != of EOF.
 *
 * Shortcut to access EOF:
 *     Windows: CTRL+Z
 *     Unix like systems: CTRL+D.
 */
    printf("getchar() != EOF: %d \n\r", getchar() != EOF);
}

// 
// End of file.
//

