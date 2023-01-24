/*
 * Exercise 2-5: Write the function any(s1, s2), which returns the first
 * location in the string s1 where any character from the string s2 occurs, or
 * -1 if s1 contains no characters from s2. (The standard library function
 *  strpbrk does the same job but returns a pointer to the location.)
 *  
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */

#include "stdio.h"

#define MAXLINE 1000     /* maximum input line size */

int any(char s1[], char s2[]);
int getLine (char line[], int maxline);

/* squeeze: returns the first location in the string s1 where any character from
            the string s2 occurs, or -1 if s1 contains no characters from s2*/
int any(char s1[], char s2[])
{
    int i, j, k;
    int skip;

    for (i = 0; s1[i] != '\0'; i++ )
        for(k = 0; s2[k] != '\0'; k++)
           if (s1[i] == s2[k])
               return i;

    return -1;
}

void main (void)
{
    char s1[MAXLINE];
    char s2[MAXLINE];
    int n;

    printf("Enter s1[]: ");

    while(getLine(s1,MAXLINE))
    {
        printf("Enter s2[]: ");
        getLine(s2,MAXLINE);

        printf("any? ->");

        if((n = any(s1, s2)) >= 0 )
            printf("s1[%d]: %c\n", n, s1[n]);
        else
            printf("no one\n");

        printf("Enter s1[]: ");
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

