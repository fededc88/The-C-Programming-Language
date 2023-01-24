/*
 * Exercise 3-3. Write a function expand(s1,s2) that expands shorhand notations
 * like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
 * Allow for letters of either case and digits, and be prepared to handle cases
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
 * literally.
 *  
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */
  
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine (char line[], int maxline);
void expand(char s1[], char s2[]);

/* expand: expands shorthand notations like a-z in the string s1 into the
 * equivalent xomplete list abc...xyz in s2. */
void expand(char s1[], char s2[])
{
    int s1Idx = 0; /* s1 string index */
    int s2Idx = 0; /* s2 string index */

    char start;
    char end;

    while(s1[s1Idx++] != '\0')
    {
        /* Find next - character posittion until end of string */
        while(s1[s1Idx] != '-')
        {
            s1Idx++;
            if(s1[s1Idx] == '\0')
                break;
        }

        /* Handle leading - */
        if(s1Idx == 0)
            continue;

        /* Handle trailing - */
        if(s1[s1Idx + 1] == '\n')
            break;

        /* select expansion character limits and expand to s2 */
        start = s1[s1Idx - 1];
        end = s1[s1Idx + 1];
        for(s2Idx; start <= end; start++, s2Idx++)
            s2[s2Idx] = start;
    }

    /* close s2 string with end of string character */
    s2[s2Idx] = '\0';

    return;
}

int main (void)
{
    char line[MAXLINE] = {"\0"}; /* input line */
    char s2[MAXLINE] = {"\0"}; /* output line */
 
/*
 * Shortcut to access EOF:
 *     Windows: CTRL+Z
 *     Unix like systems: CTRL+D.
 */
    while(getLine(line, MAXLINE))
    {
        expand(line, s2);
        printf("%s\n", s2);
    }

    return 0;
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
