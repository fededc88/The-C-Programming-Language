/*
 * Exercise 1-22: Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */

/* 
   NOTE: I fold line when a non-blank character occurs within the last 15% of
   line characters but could not be the last non-blank occurrence of the line.
   Could have been corrected but I prefer to keep going with next exercises.
   If you want to edit it and pull request it feel free!, I would appreciate it.
 */

#include <stdio.h>

#define MAXLINE 1000     /* maximum input line size */

int getLine (char line[], int maxline);
void fold (char s[]);

int main (void)
{
    char line[MAXLINE]; /* current input line */
    
    while(getLine(line, MAXLINE)){
        fold( line );
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

/* fold(s): replace strings of blanks by the minimum number of tabs and blanks
             to achieve the same spacing*/
void fold (char s[])
{

#define LINEN 80    /* length of the line*/

    int i, j;
    int len;
    int line;
    char buff[MAXLINE];

    /* preserve original string */
    for(len = 0; s[len] != '\0'; len++)
        buff[len] = s[len];
    buff[len] = '\0';

    //NOTE: It isn't necessary check that the string have at least 1 character
    //because of our getLine function implementation. 

    /* fold string */
    for(i = 0, j = 0, line = 0; buff[i] != '\0'; i++)
    {
       /* look for blanks on the last 15% of the line */ 
        if( (i % LINEN) >= (LINEN*0.85) && (j / LINEN) >= line)
        {
            if(buff[i] == ' ' || buff[i] == '\t')
            {
                s[j++] = '\n';
                line++;
                while(buff[i+1] == ' ' || buff[i+1] == '\t')
                    i++;
            } else
                s[j++] = buff[i]; /* insert everithing else */

        }
        /* if the en of line is reached */
        else if ((i / LINEN) > line )
        {
            s[j++] = '\n';
            line++;
            i--;
            while(buff[i+1] == ' ' || buff[i+1] == '\t')
                i++;
        }
        else
           s[j++] = buff[i]; /* insert everithing else */
    }

    s[j]  =  '\0';
}

// 
// End of file.
//
