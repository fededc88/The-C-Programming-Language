
/*
 * Exercise 1-11. How would you test the word count program? Whay kind of imput
 * are most likely to uncover bugs if there are any?
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kinrdg of
 * submision are welcome. 
 */

#include <stdio.h>

#define IN 1       /* inside a word */
#define OUT 0      /* outside a word */

/* count lines, words, and characters in input */
int main(void)
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    /*
     * Shortcut to access EOF:
     *     Windows: CTRL+Z
     *     Unix like systems: CTRL+D.
     */
    while ((c = getchar()) != EOF)
    {
        ++nc;

        if (c == '\n')
        {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("lines: %d\nwords: %d\ncharacters: %d\n", nl, nw, nc);
}

// 
// End of file.
//
