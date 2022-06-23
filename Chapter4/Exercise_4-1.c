/*
 * Exercise 4-1. Write the function strindex(s,t), which returns the position of
 * the rightmost occurrence of t in s, or -1 if there none.
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome.
 */

/* strindex: return index of the rightmost t occurrence in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k, l;

    l = -1;

    for(i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            l = i;
    }

    return l;
}

//
// End of file.
//
