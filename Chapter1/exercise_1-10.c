
/*
 * Exercise 1-10. Write a program to copy its input to its putput, replacing each
 * tab by \t, each backspace by \b, and each backslash by \\. This makes tabs
 * and backspaces visible in an unanmbiguous way.
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kinrdg of
 * submision are welcome. 
 */
  
#include <stdio.h>

void main (void)
{
 
    int c;

/*
 * Shortcut to access EOF:
 *     Windows: CTRL+Z
 *     Unix like systems: CTRL+D.
 */
    while ((c = getchar()) != EOF) {

        if ( c == '\t' )
        {
            putchar('\\');
            putchar('t');
        }
        else if  ( c == '\b' )
        {
            putchar('\\');
            putchar('b');
        }
        else if ( c == '\\' )
        {
            putchar('\\');
            putchar('\\');
        }
        else 
            putchar(c);
    }
    return;
}

// 
// End of file.
//
