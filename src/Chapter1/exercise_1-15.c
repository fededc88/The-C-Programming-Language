/*
 * Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion.  
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */

#include <stdio.h>

/*
 * Declares function prototype 
 */

float fahr2cels ( float fahr );

/*
 * print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point
 * vesion 
 */

int main (void)
{
    float fahr;
    int lower, upper, step;

    lower = 0;   /* lower limit of temperature table */
    upper = 300; /*upper limit */
    step = 20;   /*step size */

    fahr = lower;
    printf("  F    \t   C\n\r");
    printf("-----------------\r\n");

    while (fahr <= upper) 
    {
        printf("%3.0f \t %6.1f\n", fahr, fahr2cels(fahr));
        fahr = fahr + step;
    }

    return 0;
}

/*
 * fahr2cels: converts a fahrenheit to celsius
 */
float fahr2cels ( float fahr ) 
{
    float celsius;

    celsius = (5.0/9.0) * (fahr-32.0);

    return celsius;
}


// 
// End of file.
//

