/*
 * Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit
 * table
 * 
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */

#include <stdio.h>

/*
 * print Celsius-Fahrenheit table for fahr = 0, 20, ..., 300; floating-point
 * vesion 
 */

void main (void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = -17.8;   /* lower limit of temperature table */
    upper = 148.9;   /* upper limit */
    step = 11.11;    /* step size */

    celsius = lower;
    printf("  C   \t   F\n\r");
    printf("----------------\n\r");

    while (celsius <= upper) 
    {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%6.1f \t %3.0f\n", celsius,fahr);

        celsius = celsius + step;

    }
}

// 
// End of file.
//

