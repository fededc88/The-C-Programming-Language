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
    unsigned long long int acum;
    
    printf("\n Computed values\n");
    printf("----------------------------------------\n");

    /* characters */
    char _char;
    printf("`char': ");
    for(_char = 1, acum = 1; _char > 0; _char*=2, acum*=2);
    printf("(%d) to %llu\n", _char, (acum - 1));

    printf("`signed char': ");
    printf("(%d) to %llu\n", _char, (acum - 1));

    unsigned char _uchar;
    printf("`unsigned char': ");
    for(_uchar = 1, acum = 1; _uchar > 0; _uchar*=2, acum*=2);
    printf("%d to %llu\n", 0, (acum - 1));

    printf("\n");

    /* Integers */
    short int _short_int;
    printf("`signed short int': ");
    for(_short_int = 1, acum = 1; _short_int > 0; _short_int*=2, acum*=2);
    printf("(%d) to %llu\n", _short_int, acum - 1);

    unsigned short int _ushort_int;
    printf("`unsigned short int': ");
    for(_ushort_int = 1, acum = 1; _ushort_int > 0; _ushort_int*=2, acum*=2);
    printf("%d to %llu\n", 0, (acum - 1));

    int _int;
    printf("`signed int':  ");
    for(_int = 1, acum = 1; _int > 0; _int*=2, acum*=2);
    printf("(%d) to %llu\n", _int, acum - 1);

    unsigned int _uint;
    printf("`unsigned int': ");
    for(_uint = 1, acum = 1; _uint > 0; _uint*=2, acum*=2);
    printf("%d to %llu\n", 0, (acum -1));

    long int _long_int;
    printf("`signed long int': ");
    for(_long_int = 1, acum = 1; _long_int > 0; _long_int*=2, acum*=2);
    printf("(%ld) to %llu\n", _long_int, (acum - 1));

    unsigned long int _ulong_int;
    printf("`unsigned long int': ");
    for(_ulong_int = 2, acum = 1; _ulong_int > 0; _ulong_int*=2, acum*=2);
    printf("%d to %llu\n", 0, ((acum-1)*2+1));

    long long int _long_long_int;
    printf("`signed long long int': ");
    for(_long_long_int = 1, acum = 1; _long_long_int > 0; _long_long_int*=2, acum*=2);
    printf("(%lld) to %llu\n", _long_long_int, (acum - 1));

    unsigned long long int _ulong_long_int;
    printf("`unsigned long long int': ");
    for(_ulong_long_int = 1, acum = 1; _ulong_long_int > 0; _ulong_long_int*=2, acum*=2);
    printf("%d to %llu\n", 0, ((acum-1)*2+1));

	printf("\n");

	/* finite floating points numbers */

    /*
     * The representation of a floating-point data in a format consist of:
     *  ― tripes (sign, exponent, significand); in radix b, the floating-point
     *    number represented by a triple is: 
     *
     *    (-1)**sign * b**exponent * significand
     *    
     *  ― +inf, -inf
     *  ― qNan, sNan
     * 
     * The set of infinite floating-point numbers representable within a
     * particular format is determined by the folowing integer parameters.
     * Each format is identified by its radix and the number o bits in its
     * encoding.
     */
    long double b = 2.0; // the radix
    int p;  // the number of digits in the significad (precision)
    int emax; // the maximun exponent e
    int emin; // the minimun exponen e

    
    long double sign = 1.0;
    long double exponent = 1.0; // exponent
    long double significand = 1.0; // significand

    /* Parameters defining basic format floating-point numbers
     *           | Binary format(b=2)
     * parameter | binary32 | binary53 | binary68 |
     * p,digits  |    24    |    53    |    113   |
     * emax      |   +127   |  +1023   |   +1683  |
     *
     *  ** emin shall be 1 − emax for all formats.
     */

    /* 
     * The smalles positive normal floating-point numbes is b**emin and the
     * largest is b**emax*(b-b**(1-p))
     */

	printf("`float': ");

#define BINARY32_P 24
#define BINARY32_EMAX 127

    double float_min;
    double float_max;

    /* b**emax */
    for(emax = 0; emax < (BINARY32_EMAX); emax++)
        exponent *= b;

    for(emin = 1; emin < (BINARY32_P - 1); emin++)
        significand /= b;

    significand = b - significand;

    float_max = sign*significand*exponent;
    float_min = sign*significand/exponent;

    printf("%g to %g (FLT_MIN - FLT_MAX)\n", float_min, float_max);
    
	printf("'double': ");

#define BINARY64_P 53
#define BINARY64_EMAX 1023

    double double_min;
    double double_max;

    exponent = 1.0; // exponent
    significand = 1.0; // significand

    /* b**emax */
    for(emax = 0; emax < (BINARY64_EMAX); emax++)
        exponent *= b;

    for(emin = 0; emin < (BINARY64_P - 1); emin++)
        significand /= b;

    significand = b - significand;

    double_max = sign*significand*exponent;
    double_min = sign*significand/exponent;

    printf("%lg to %lg (DBL_MIN - DBL_MAX)\n", double_min, double_max);

	printf("'long double': ");

#define BINARY128_P 113
#define BINARY128_EMAX 16383

    long double long_double_min;
    long double long_double_max;

    exponent = 1.0; // exponent
    significand = 1.0; // significand

    /* b**emax */
    for(emax = 0; emax < (BINARY128_EMAX); emax++)
        exponent *= b;

    /* b**emin */
    for(emin = 0; emin < (BINARY128_P - 1); emin++)
        significand /= b;

    significand = (2.0 - significand);

    long_double_max = sign*1.999999999999*exponent;
    long_double_min = sign*significand/exponent;

    printf("%Lg to %Lg (LDBL_MIN - LDBL_MAX)\n", long_double_min, long_double_max);
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
