/*
 * Exercise 1-3. Modify the temperature conversion program to print a heading
 * above the table.  
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */

#include <stdio.h>

/*
 * print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point
 * vesion 
 */

void main (void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* lower limit of temperature table */
    upper = 300; /*upper limit */
    step = 20;   /*step size */

    fahr = lower;
    printf("  F    \t   C\n\r");
    printf("-----------------\r\n");

    while (fahr <= upper) 
    {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f \t %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

// 
// End of file.
//

