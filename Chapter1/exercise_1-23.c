/*
 * Exercise 1-23: Write a program to remove all comments froma  C program. Don't
 * forget to handle quoted strings characer constants properly. C coments do not
 * nest.
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */

/* 
 * NOTE: For Unix like system, on bash run: ./exercise_1-23 < exercise_1-23.c
 */

#include <stdio.h>

#define MAXLINE 1000     /* maximum input line size */

#define TRUE 1
#define FALSE 0

int getLine (char line[], int maxline);
void remove_comments (char s[]);

int main (void)
{
    char line[MAXLINE]; /* current input line */
    
    while(getLine(line, MAXLINE))
    {
        remove_comments( line );
        printf("%s",line);
    }
    
    return 0;
}

/* getLine: reads line into s[], return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n') 
        s[i++] = c;
    
    s[i] = '\0';
    return i;
}

/* remove_comments: reads line and return line without comments */
void remove_comments (char s[])
{
    int i, j;
    int len;
    static int block_comment = FALSE;
    static int quote = FALSE;
    static int quote_char = FALSE;
    char buff[MAXLINE];

    /* preserve original string */
    for(len = 0; s[len] != '\0'; len++)
        buff[len] = s[len];
    buff[len] = '\0';

    //NOTE: It isn't necessary check that the string have at least 1 character
    //because of our getLine function implementation. 
    
    i=0;
    j=0;

    while(buff[i] != '\0')
    {
        if(block_comment == TRUE)
        {
            if((buff[i-1] == '*') && (buff[i] == '/'))
                block_comment = FALSE;
            i++;
        }
        else if (quote == TRUE)
        {
            if(buff[i] == '"' )
                quote = FALSE;
            s[j++] = buff[i++]; /* insert everithing else */
        }
        else if (quote_char == TRUE)
        {
            if(buff[i] == '\\') 
            {
                s[j++] = buff[i++]; /* insert everithing else */
            } else if(buff[i] == '\'') 
                quote_char = FALSE;
            s[j++] = buff[i++]; /* insert everithing else */
        }
        else if (buff[i] == '/')
        {
            i++;

            if( buff[i] == '\0')
                    break;

            if( buff[i] == '/' )
            {
                while(buff[++i] != '\n');
                break;
            }

            else if(buff[i] == '*')
                block_comment = TRUE;

            else
            {
                s[j++] = buff[i-1]; /* insert everithing else */
                s[j++] = buff[i]; /* insert everithing else */
            }
        }
        else if (buff[i] == '"')
        {
                quote = TRUE;
                s[j++] = buff[i]; /* insert everithing else */
        }
        else if (buff[i] == '\'')
        {
                quote_char = TRUE;
                s[j++] = buff[i++]; /* insert everithing else */
        }
        else
            s[j++] = buff[i++]; /* insert everithing else */
    }

    s[j]  =  '\0';
}

// 
// End of file.
//

