/*
 * Exercise 1-24: Write a program to check a C program for rudimentary syntax
 * errors like unbalanced parentheses, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments. (This program
 * is hard if you do it in full fenerality.)
 */

#include <stdio.h>

#define MAXLINE 1000     /* maximum input line size */

#define TRUE 1
#define FALSE 0

int getLine (char line[], int maxline);
void remove_comments (char s[]);
void rudimentary_syntax_check (char s[]);

int main (void)
{
    char line[MAXLINE]; /* current input line */
    
    while(getLine(line, MAXLINE))
    {
        remove_comments( line );
        rudimentary_syntax_check ( line );

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

/* remove_comments: reads a line and return it without comments */
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
            s[j++] = buff[i++]; /* insert everything else */
        }
        else if (quote_char == TRUE)
        {
            if(buff[i] == '\\') 
            {
                s[j++] = buff[i++]; /* insert everything else */
            } else if(buff[i] == '\'') 
                quote_char = FALSE;
            s[j++] = buff[i++]; /* insert everything else */
        }
        /* both comments types in C are open with '/' */
        else if (buff[i] == '/')
        {
            i++;
            
            /* Precautionary in case '/' were the las character */
            if( buff[i] == '\0') 
                    break;

            /* single line comment */
            if( buff[i] == '/' )
            {
                while(buff[++i] != '\n'); // Single line comment ends on 'new-line'
                break;
            }

            /* block comment */
            else if(buff[i] == '*')
                block_comment = TRUE;

            /* something else */
            else
                s[j++] = buff[i-1]; /* insert everything else */
        }
        /* starts a string quotation */
        else if (buff[i] == '"')
        {
                quote = TRUE;
                s[j++] = buff[i++]; /* insert everything else */
        }
        /* starts a character quotation */
        else if (buff[i] == '\'')
        {
                quote_char = TRUE;
                s[j++] = buff[i++]; /* insert everything else */
        }
        /* everything else should be copied */
        else
            s[j++] = buff[i++]; /* insert everything else */
    }

    s[j]  =  '\0';
}

// 
// End of file.
//

