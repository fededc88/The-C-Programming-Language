/*
 * Exercise 2-1: Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropiate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 * */

#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_appropiate_values_from_std_header(void);

int main (void)
{

    print_appropiate_values_from_std_header();

    return 0;


}

void print_appropiate_values_from_std_header(void)
{
    printf("\nAppropiate values from standard headers\n");
    printf("----------------------------------------\n");

    /* charcters */
    printf("`char': ");
    printf("(%d) to %d (CHAR_MIN - CHAR_MAX)\n", CHAR_MIN, CHAR_MAX);

    printf("`signed char': ");
    printf("(%d) to %d (SCHAR_MIN - SCHAR_MAX)\n", SCHAR_MIN, SCHAR_MAX);

    printf("`unsigned char': ");
    printf("0 to %d (0 - UCHAR_MAX)\n", UCHAR_MAX);

	printf("\n");

    /* Integers */
    printf("`signed short int': ");
    printf(" (%d) to %d (SHRT_MIN - SHRT_MAX) \n", SHRT_MIN, SHRT_MAX);

    printf("`unsigned short int': ");
    printf("0 to %u (UINT_MIN - UINT_MAX) \n", SHRT_MAX);

    printf("`signed int':  ");
    printf("(%d) to %d (INT_MIN - INT_MAX)\n", INT_MIN, INT_MAX);

    printf("`unsigned short int': ");
    printf("0 to %u (0 - UINT_MAX)\n", UINT_MAX);
    
    printf("`signed long int': ");
    printf("(%ld) to %ld (LONG_MIN LONG_MAX)\n", LONG_MIN, LONG_MAX);

    printf("`unsigned long int': ");
    printf("0 to %lu (0 - ULONG_MAX)\n", ULONG_MAX);

    printf("`signed long long int': ");
    printf("(%lld) to %lld (LLONG_MIN - LLONG_MAX) \n", LLONG_MIN, LLONG_MAX);

    printf("`unsigned long long int': ");
    printf("0 to %llu (0 - ULLONG_MAX)\n", ULLONG_MAX);

	printf("\n");

	/* finite floating points numbers */
	printf("`float': ");
    printf("%g to %g (FLT_MIN - FLT_MAX)\n", FLT_MIN, FLT_MAX);
	printf("'double': ");
    printf("%lg to %lg (DBL_MIN - DBL_MAX)\n", DBL_MIN, DBL_MAX);
	printf("'long double': ");
    printf("%Lg to %Lg (LDBL_MIN - LDBL_MAX)\n", LDBL_MIN, LDBL_MAX);

}

//
// End of file.
//
