/*
 * Exercise 1-18: Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blanks lines.
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */

#include <stdio.h>

#define MAXLINE 1000     /* maximum input line size */

int getLine (char line[], int maxline);
void cleanline( char line[]);

/* remove trailing blanks and tabs from each line of input */
int main ( void )
{
    char line[MAXLINE]; /* current input line */

    /*
     * Shortcut to access EOF:
     *     Windows: CTRL+Z
     *     Unix like systems: CTRL+D.
     */
    while(getLine(line, MAXLINE)){
        cleanline( line );
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

/* cleanline: clean trailing blanks & tabs from s, return nothing */
void cleanline(char s[])
{
    int i;
    int last_char;

    i = 0;
    last_char = 0;

    /* scan string to find last valid character */
    while(s[i]){
        if((s[i] != ' ') && (s[i] != '\t'))
            last_char = i;
        i++;
    }

    /* clean string from last valid char */
    if(last_char == 0)
        s[last_char] = '\0';
    else
        s[last_char + 1] = '\0';
}

// 
// End of file.
//
