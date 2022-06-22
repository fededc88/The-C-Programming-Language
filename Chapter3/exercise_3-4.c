/*
 * Exercise 3-4. In a two's complement number representation, our version of
 * itoa does not handle the largest negative number, that is, the value of n
 * equal to -(2^wordsize-1). Explain why not. Modify it to print that value
 * correctly, regardless of the machine on which it runs.
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome.
 */

/*
 * PROBLEM:
 * The most common method of representing signed numbers is two's complement
 * where the most significant bit (MSB) is used to indicate if it is positive or
 * negative and remaining bits are used to store the actual value of the number.
 * Positive numbers always start with a 0 and in this case the smallest positive
 * number will be the smallest binary value.
 * On the other hand, negative numbers always start with a MSB 1 and the
 * smallest negative number will be the largest binary value possible.
 * For example in a four-bit case, 0b0001 equals 1 and 0b1111 equals -1.
 *
 * The range of values that a signed integer can hold in its two's complement
 * representation form stands from -(2^wordsize-1) to -(2^wordsize-1)-1.
 *
 * In the example form of itoa() the n argument that holds the value to be
 * translated is declared signed int but then made positive.
 *
 * When largest negative number ( -(2^wordsize-1) ) is negated, we get a number
 * that is equal to 2^wordsize-1, which is larger than the largest positive
 * number ( (2^wordsize-1)-1 ) that a signed int can hold. This will overflow
 * the signed int and cause unexpected results.
 *
 * SOLUTION:
 * To solve this problem, we can use an unsigned int to hold the positive n
 * value when negated after been checked for whether n is negative or not. 
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;
    unsigned int un;

	//if ((sign = n) < 0) /* record sign */
		un = (unsigned int) n;         /* make n positive */
	i = 0;
	do {       /* generate digits in revered order */
		s[i++] = un % 10 + '0';    /* get next digit */
	} while ((un /= 10) != 0);     /* delete it */
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

	itoa(0, line); /* do-while loop is necessary for 0 */
	printf("%i -> %s\n", 0, line);
	itoa(INT_MAX, line);
	printf("%i -> %s\n", INT_MAX, line);
	itoa(INT_MIN, line);
	printf("%i -> %s\n", INT_MIN, line);

	return 0;
}

// 
// End of file.
//

