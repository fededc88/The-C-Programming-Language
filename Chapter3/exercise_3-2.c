/*
 * Exercise 3-2. Write a function escape(s.t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t as it copies the
 * string t to s. Use a switch. Write a funtion for the other direction as well,
 * converting escape sequences into the real characters.
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */
  
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine (char line[], int maxline);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

/* escape: converts characters like newline and tab into visible escape sequences
 * like \n and \t as it copies the string t to s */
void escape(char s[], char t[])
{
    int is = 0;
    int it = 0;

    while (t[it] != '\0')
    {
        switch(t[it])
        {
            case '\n':
                s[is++] = '\\';
                s[is++] = 'n';
                break;

            case '\t':
                s[is++] = '\\';
                s[is++] = 't';
                break;

            case '\b':
                s[is++] = '\\';
                s[is++] = 'b';
                break;

            case '\\' :
                s[is++] = '\\';
                s[is++] = '\\';
                break;

            default:
                s[is++] = t[it];
        }
        it++;
    }

    s[is++] = '\0';
}

/* unescape: converts visible scape sequences like \n and \t into characters as it
 * copies the string t to s */
void unescape(char s[], char t[])
{
    int is = 0;
    int it = 0;

    while (t[it] != '\0')
    {
        switch(t[it])
        {
            case '\\':
                switch (t[++it])
                {
                    case 'n':
                        s[is++] = '\n';
                        break;

                    case 't':
                        s[is++] = '\t';
                        break;

                    case 'b':
                        s[is++] = '\b';
                        break;

                    case '\\' :
                        s[is++] = '\\';
                        break;
                }
                break;

            default:
                s[is++] = t[it];
        }
        it++;
    }

    s[is++] = '\0';
}

int main (void)
{
    char s[MAXLINE] = {"\0"};
    char line[MAXLINE] = {"\0"}; /* input line */
 
    int c;

/*
 * Shortcut to access EOF:
 *     Windows: CTRL+Z
 *     Unix like systems: CTRL+D.
 */
    while(getLine(line, MAXLINE))
    {
        escape(s, line);
        printf("%s\n", s);
        unescape(line, s);
        printf("%s\n", line);
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
