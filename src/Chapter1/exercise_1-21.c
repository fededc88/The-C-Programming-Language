/*
 * Exercise 1-21: Write a program entab that replace strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as fot detab.
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */

/* When either a tab or a single blank would suffice to reach a tab stop, wich
 * should be given preference?
 *
 * Answer: Should be given preference to the tab.
 */ 

#include <stdio.h>

#define MAXLINE 1000     /* maximum input line size */

int getLine (char line[], int maxline);
void entab (char s[]);

int main (void)
{
    char line[MAXLINE]; /* current input line */
    
    while(getLine(line, MAXLINE)){
        entab( line );
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

/* entab(s): replace strings of blanks by the minimum number of tabs and blanks
             to achieve the same spacing*/
void entab (char s[])
{

#define TABSN 4    /* number of spaces per tab */

    int i, j;
    int len;
    int tabs;
    int spaces;
    char buff[MAXLINE];

    /* preserve original string */
    for(len = 0; s[len] != '\0'; len++)
        buff[len] = s[len];
    buff[len] = '\0';

    //NOTE: It isn't necessary check that the string have at least 1 character
    //because of our getLine function implementation. 

    /* entab string */
    for(i = 0, j = 0; buff[i] != '\0'; i++)
        if( buff[i] == ' '){
            for(spaces = 0; buff[i] == ' '; i++, spaces++); /* calc sub-string of spaces */
              
            i--;
            tabs = spaces / TABSN;   /* calc number of tabs */
            spaces = spaces % TABSN; /* calc number of spaces */

            while( tabs-- > 0) /* insert tabs */
                s[j++] = '\t';

            while( spaces-- > 0) /* insert remaning spaces */
                s[j++] = ' ';
        } else
            s[j++] = buff[i]; /* insert everithing else */

    s[j]  =  '\0';
}

// 
// End of file.
//
