/* 1.3 Fahrenheit to Celsius with for loop, page 13 */

#include <stdio.h>

/* print Fahrenheit-Celsius table */
main()
{
    int fahr;
    
    for(fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}