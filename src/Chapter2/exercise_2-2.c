/*
 * Exercise 2-2: Write a loop equivalent to the for loop above without using &&
 * or ||.
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */

#include <stdio.h>

/* getLine_loop_equivalent: reads line into s[], return length */
int getLine_loop_equivalent(char s[], int lim)
{
    int c, i;

    /* loop equivalent of:
     *     for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
     *         s[i] = c;
     */
    for (i=0; ; ++i)
    {
        // Before reading a new character it is necessary to check that there ir
        // romm to store it in the array s
        if(!(i<lim-1))
            break;

        /* The precedence of && is higher than that of ||, and both are lower
         * than relational and equality operators
         */

        // The precedence of != is higher than assignment, so because of the
        // parentheses
        c = getchar();
        // comes before that:
        if(c == '\n')
            break;

        if(c == EOF)
            break;

        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

// 
// End of file.
//
