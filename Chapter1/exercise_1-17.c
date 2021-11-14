/*
 * Exercise 1-17: Write a program to print all input lines that are longer than
 * 80 characters.
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */

#include <stdio.h>
#define LINES 20        /* maximum number of lines longer than 80 characters admited */
#define MAXLINE 1000    /* maximum input line size */
#define LINE_LENGHT 80  /* print all lines of this length */

int getLine (char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(void)
{
    int len;            /* current line length */
    int actual_line;    /* actual line in buffer */
    char line[MAXLINE]; /* current input line */
    char longest[LINES][MAXLINE]; /* longest line saved here */

    actual_line = 0;

    /*
     * Shortcut to access EOF:
     *     Windows: CTRL+Z
     *     Unix like systems: CTRL+D.
     */
    while ((len = getLine(line, MAXLINE)) > 0)
        if (( len > LINE_LENGHT ) && ( actual_line < LINES )) {
            copy(longest[actual_line], line);
            actual_line ++;
        }

    for(int j = 0; actual_line > 0 ; j++, actual_line--)     /* there was a line */
        printf("len > %d: \"%s\"\n", LINE_LENGHT, longest[j]);

    return 0;
}

/* mygetline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
   // if (c == '\n') {
   //     s[i] = c;
   //     ++i;
   // }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

// 
// End of file.
//
