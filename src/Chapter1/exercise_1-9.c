/*
 * Exercise 1-9. Write a program to copy its input to its putput, replacing each
 * string of one or more blanks by a single blank.
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */
  
#include <stdio.h>

void main (void)
{
 
    int new_c, last_c;

/*
 * Shortcut to access EOF:
 *     Windows: CTRL+Z
 *     Unix like systems: CTRL+D.
 */
    while ((new_c = getchar()) != EOF) {

        if ( last_c != ' ' )
            putchar(new_c);

        last_c = new_c;
    }
    return;
}

// 
// End of file.
//
