/*
 * Exercise 2-1: Write the function htoi(s), which converts  string of
 * hexadecimal digits (including an optional 0x or 0x) into its equivalent
 * integer value. The allowable digits are 0 through 0, a through f, and A
 * trhrough F. 
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 * */

#include "stdio.h"

#define MAXLINE 1000     /* maximum input line size */

int htoi(const char s[]);
int getLine (char line[], int maxline);

/* htoi: converts string of hexadecimal digits into its equivalent integer value */
int htoi(const char s[])
{
    int i, n;

    n = 0;

    if(s[0] != '0' && (s[1] != 'x' && s[1] != 'X'))
        return 0;

    for (i = 2; s[i] != '\0'; i++)

        if ( s[i] >= '0' && s[i] <= '9' ) 
        {
            n = 16 * n + (s[i] - '0');
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            n = 16 * n + (s[i] - 'A' + 10);
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            n = 16 * n + (s[i] - 'a' + 10);
        }

    return n;
}

void main (void)
{
    char s[MAXLINE];
    int n;

    while(getLine(s,MAXLINE))
    {
        n = htoi((const char *)s);
        printf("%s -> %d\n", s, n);
    }
}

/* getLine: reads line into s[], return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

//
// End of file.
//
