/*
 * Exercise 1-8. Write a program to count blanks, tabs, and new lines.
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */
  
#include <stdio.h>

void main (void)
{
 
    int c;
    long n1, n2, n3;

    n1 = 0;
    n2 = 0;
    n3 = 0;

/*
 * NOTE: Counts blank, tabs and new lines characters until you type EOF.
 * 
 * Shortcut to access EOF:
 *     Windows: CTRL+Z
 *     Unix like systems: CTRL+D.
 */
    while ((c = getchar()) != EOF) {

        if ( c == ' ')
            ++n1;
        if ( c == '\t')
            ++n2;
        if ( c == '\n' )
            ++n3;
    }

    printf("blanks: %ld, tabs: %ld, nl: %ld \n" , n1, n2, n3);
}

// 
// End of file.
//
