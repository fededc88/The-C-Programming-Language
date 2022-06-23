
/*
 * Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into
 * a base b character representation in the string s. In particular,
 * itob(n,s,16) formats n as a hexadecimal integer in s.
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLINE 1000

void itob(int n, char s[], unsigned int b);
void reverse(char s[]);

/* itoa: convert n to characters in s */
void itob(int n, char s[], unsigned int b)
{
	int i, sign;
    unsigned int un;

	//if ((sign = n) < 0) /* record sign */
		un = (unsigned int) n;         /* make n positive */
	i = 0;
	do {       /* generate digits in revered order */
		s[i++] = un % b + '0';    /* get next digit */
        if( b == 16 && s[i-1] > 9)
            s[i-1] += 7;
	} while ((un /= b) != 0);     /* delete it */


    if(b == 2) 
    {
        s[i++] = 'b';
        s[i++] = '0';
    }

    if(b == 16) 
    {
        s[i++] = 'x';
        s[i++] = '0';
    }
    if(b == 10)
        if (n < 0) s[i++] = '-';

    s[i] = '\0';
	reverse(s);
}

/* reverse: reverse the order of the characters in the string s */
void reverse(char s[])
{
	int c, j;

	for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main(void)
{
    char line[MAXLINE] = {"\0"}; /* input line */

	itob(0, line, 2); /* do-while loop is necessary for 0 */
	printf("%i --2-> %s\n", 0, line);
	itob(INT_MAX, line, 2);
	printf("%i --2-> %s\n", INT_MAX, line);
	itob(INT_MIN, line, 2);
	printf("%i --2-> %s\n", INT_MIN, line);

	itob(0, line, 16); /* do-while loop is necessary for 0 */
	printf("%i --16-> %s\n", 0, line);
	itob(INT_MAX, line, 16);
	printf("%i --16-> %s\n", INT_MAX, line);
	itob(INT_MIN, line, 16);
	printf("%i --16-> %s\n", INT_MIN, line);

  
	return 0;
}

// 
// End of file.
//

