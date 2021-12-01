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
void compute_appropiate_values(void);

int main (void)
{

    print_appropiate_values_from_std_header();

    compute_appropiate_values();

    return 0;


}

void compute_appropiate_values(void)
{
    long long int acum;
    
    printf("\n Computed values\n");
    printf("----------------------------------------\n");

    /* characters */
    char _char;
    printf("`char': ");
    for(_char = 1, acum = 1; _char > 0; _char*=2, acum*=2);
    printf("(%d) to %lld\n", _char, (acum - 1));

    printf("`signed char': ");
    printf("(%d) to %lld\n", _char, (acum - 1));

    unsigned char _uchar;
    printf("`unsigned char': ");
    for(_uchar = 1, acum = 1; _uchar > 0; _uchar*=2, acum*=2);
    printf("(%d) to %lld\n", 0, (acum - 1));

    printf("\n");

    /* Integers */
    short int _short_int;
    printf("`signed short int': ");
    for(_short_int = 1, acum = 1; _short_int > 0; _short_int*=2, acum*=2);
    printf("(%d) to %lld\n", _short_int, acum - 1);

    unsigned short int _ushort_int;
    printf("`unsigned short int': ");
    for(_ushort_int = 1, acum = 1; _ushort_int > 0; _ushort_int*=2, acum*=2);
    printf("(%d) to %lld\n", 0, (acum - 1));

    int _int;
    printf("`signed int':  ");
    for(_int = 1, acum = 1; _int > 0; _int*=2, acum*=2);
    printf("(%d) to %lld\n", _int, acum - 1);

    unsigned int _uint;
    printf("`unsigned int': ");
    for(_uint = 1, acum = 1; _uint > 0; _uint*=2, acum*=2);
    printf("(%d) to %lld\n", 0, (acum -1));

    long int _long_int;
    printf("`signed long int': ");
    for(_long_int = 1, acum = 1; _long_int > 0; _long_int*=2, acum*=2);
    printf("(%ld) to %lld\n", _long_int, (acum - 1));

    unsigned long int _ulong_int;
    printf("`unsigned long int': ");
    for(_ulong_int = 1, acum = 1; _ulong_int > 0; _ulong_int*=2, acum*=2);
    printf("(%d) to %lld\n", 0, (acum - 1));

    long long int _long_long_int;
    printf("`signed long long int': ");
    for(_long_long_int = 1, acum = 1; _long_long_int > 0; _long_long_int*=2, acum*=2);
    printf("(%lld) to %lld\n", _long_long_int, (acum - 1));

    unsigned long long int _ulong_long_int;
    printf("`unsigned long long int': ");
    for(_ulong_long_int = 1, acum = 1; _ulong_long_int > 0; _ulong_long_int*=2, acum*=2);
    printf("(%d) to %lld\n", 0, (acum - 1));

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
    printf("0 to %u (0 - USHRT_MAX) \n", USHRT_MAX);

    printf("`signed int':  ");
    printf("(%d) to %d (INT_MIN - INT_MAX)\n", INT_MIN, INT_MAX);

    printf("`unsigned int': ");
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
