/* This program counts characters in input */
/* Ctrl-d will act as EOF character */

#include <stdio.h>

int main(void)
{
	double nc = 0;

	for (nc = 0; getchar() != EOF; ++nc)
		;

	printf("%.0f\n", nc);
}

