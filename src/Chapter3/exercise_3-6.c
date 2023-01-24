/*
 * Exercise 3-6. Write a version o itoa that accepts three arguments instead of
 * two. The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough.
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLINE 1000

void itoa(int n, char s[], unsigned char width);
void reverse(char s[]);

/* itoa: convert n to characters in s */
void itoa(int n, char s[], unsigned char width)
{
	int i, j, sign;
    unsigned int un;

	//if ((sign = n) < 0) /* record sign */
		un = (unsigned int) n;         /* make n positive */
	i = 0;
	do {       /* generate digits in revered order */
		s[i++] = un % 10 + '0';    /* get next digit */
	} while ((un /= 10) != 0);     /* delete it */
    for(; i < width; i++)
        s[i] = '0'; /* number is padded with blanks on the left if necessary */
	if (n < 0)
		s[i++] = '-';
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

	itoa(0, line, 10); /* do-while loop is necessary for 0 */
	printf("%i -> %s\n", 0, line);
	itoa(123456, line, 10); /* do-while loop is necessary for 0 */
	printf("%i -> %s\n", 0, line);
	itoa(INT_MAX, line, 10);
	printf("%i -> %s\n", INT_MAX, line);
	itoa(INT_MIN, line, 10);
	printf("%i -> %s\n", INT_MIN, line);

	return 0;
}

// 
// End of file.
//
