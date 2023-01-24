/*
 * Exercise 1-20: Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. 
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */

/* Assume a fixed set tab stops, say every n colums. Should n be a variable or a
 * symbolic parameter?
 *
 * Answer: n should be a symbolic parameter. The value of n should not be
 * modified for the user so it must remain constant throughout the duration of
 * the entire program.
 */ 

#include <stdio.h>

#define MAXLINE 1000     /* maximum input line size */

int getLine (char line[], int maxline);
void detab (char s[]);

int main (void)
{
    char line[MAXLINE]; /* current input line */
    
    while(getLine(line, MAXLINE)){
        detab( line );
        printf("%s\n",line);
    }
    
    return 0;
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

/* detab(s): detab the string s */
void detab (char s[])
{

#define TABSN 4    /* number of spaces per tab */

    int i, j, h;
    int len;
    char buff[MAXLINE];

    /* preserve original string */
    for(len = 0; s[len] != '\0'; len++)
        buff[len] = s[len];
    buff[len] = '\0';

    //NOTE: It isn't necessary check that the string have at least 1 character
    //because of our getLine function implementation. 

    /* detab string */
    for(i = 0, j = 0; buff[i] != '\0'; i++)
        if( buff[i] == '\t')
            for(h = 0; h < TABSN; h++)
                s[j++] = ' ';
        else
            s[j++] = buff[i];
    s[j]  =  '\0';
}

// 
// End of file.
//
