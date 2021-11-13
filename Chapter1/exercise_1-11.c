/*
 * Exercise 1-11. How would you test the word count program? What kind of input
 * are most likely to uncover bugs if there are any?
 *
 * The program counts lines, words, and characters, with the loose definition
 * that a word is any sequence of characters that does not contain a blank, tab
 * or newline.
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
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
