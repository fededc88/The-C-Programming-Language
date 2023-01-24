/*
 * Exercise 2-10: Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expression instead of if-else.
 *   
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */
  
#include <stdio.h>

int lower(char);

/* lower: Converts upper case letters to lower case with conditional expression
 * ASCII only */
int lower(char c)
{ 
	return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

int main(void)
{
	char c;

    /*
     * Shortcut to access EOF:
     *     Windows: CTRL+Z
     *     Unix like systems: CTRL+D.
     */

	while ((c = getchar()) != EOF)
			printf("%c", lower(c));
	return 0;
}

// 
// End of file.
//
