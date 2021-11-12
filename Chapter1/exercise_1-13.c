#include <stdio.h>

#define TRUE 1
#define FALSE 0

/*
The longest word in any of the major English language dictionaries is
pneumonoultramicroscopicsilicovolcanoconiosis, a word that refers to a lung
disease contracted from the inhalation of very fine silica particles,
specifically from a volcano; medically, it is the same as silicosis.
Histogram counts words up to 46 characters because of this.
*/
#define LENGTH 46

int main(void)
{
    int c;
    int histogram_x[LENGTH] = {0};
    int new_word;
    int letters_count;

    int first, last;

    new_word = FALSE;
    letters_count = 0;

    // count words letters
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
            new_word = TRUE;
        else
            letters_count++;

        if(new_word == TRUE)
        {
            new_word = FALSE;
            histogram_x[letters_count]++;
            letters_count = 0;
        }
    }



    first = 0;
    last = 0;
    
    // Find firs and last histogram entry to print a cosy graph
    for(int i = 1; i < LENGTH; i++)
        if(( first == 0 ) && ( histogram_x[i] != 0 ))
            first = i;
        else if (first)
            if (histogram_x[i] != 0)
                last = i;

    // Print horizontal Histogram
    printf("\nhorizontal histogram\n---------------------\n\n");
    for( int i = first; i <= last; i++)
    {
        printf("%d: ", i);

        if (histogram_x[i] != 0)
            for(int j = 1; j <= histogram_x[i]; j++)
                printf("#");

        printf("\n");
    }

    return 0;
}
