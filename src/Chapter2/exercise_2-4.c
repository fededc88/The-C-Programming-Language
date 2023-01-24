/*
 * Exercise 2-4: Write an alternate version of squeeze(s1, s2) that deletes each
 * character in s1 that matches any character in the string s2.
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */

#include "stdio.h"

#define MAXLINE 1000     /* maximum input line size */

void squeeze(char s1[], char s2[]);
int getLine (char line[], int maxline);

/* squeeze: deletes each character in s1 that matches any character in the
 * string s2 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int skip;

    for (i = j = 0; s1[i] != '\0'; i++ )
    {
        skip = 0;
        for(k = 0; s2[k] != '\0'; k++)
           if (s1[i] == s2[k])
           {
               skip = 1;
               break;
           }
        if(skip)
            continue;
        s1[j++] = s1[i];
    }
    s1[j] = '\0';
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

        printf("squeezing...\n s1[]:");
        squeeze(s1, s2);

        printf("%s\n", s1);

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

