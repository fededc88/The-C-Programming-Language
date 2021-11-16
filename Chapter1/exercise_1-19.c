/*
 * Exercise 1-19: Write a funtion reverse(s) that reverses the character string
 * s. Use it to write a program that reverses irt input at a line.
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */

#include <stdio.h>

#define MAXLINE 1000     /* maximum input line size */

void reverse(char s[]);
int getLine (char line[], int maxline);

int main (void)
{
    char line[MAXLINE]; /* current input line */
    
    while(getLine(line, MAXLINE)){
        reverse( line );
        printf("%s\n",line);
    }
    
    return 0;
}

/* reverse(s): reverses the string d */
void reverse (char s[])
{
    int i;
    int len;
    char buf;

    /* count length */
    for(len = 0; s[len] != 0; len++);

    //NOTE: It isn't necessary check that the string have at least 1 character
    //because of our getLine function implementation. 

    /* invert string */
    for(i = 0, len-- ; i < len; i ++, len--)
    {
        buf = s[i];
        s[i] = s[len];
        s[len] = buf;
    }
}

/* getLine: reads line into s[], return length */
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

// 
// End of file
//
