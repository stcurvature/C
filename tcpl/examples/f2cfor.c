/*
 * This program converts fahrenheit to celsius
 *
 */

#include <stdio.h>

/* print fahrenheit-celsius table for 
 * farh = 0, 20,....,300 
 */

int main(void)
{
	int fahr;

	for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr - 32));
	}
}
