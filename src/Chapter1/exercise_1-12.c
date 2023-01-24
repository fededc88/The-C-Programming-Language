/*
 * Exercise 1-12. Write a program that prints its input one word per line.
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submission are welcome. 
 */

#include <stdio.h>

#define IN 1       /* inside a word */
#define OUT 0      /* outside a word */

/* count lines, words, and characters in input */
int main(void)
{
    int c, state;

    state = OUT;

    /*
     * Shortcut to access EOF:
     *     Windows: CTRL+Z
     *     Unix like systems: CTRL+D.
     */
    while ((c = getchar()) != EOF)
    {
        putchar(c);

        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            putchar('\n');
        }
        else if (state == OUT)
        {
            state = IN;
        }
    }
}

// 
// End of file.
//
