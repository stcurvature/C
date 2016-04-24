/* This program copies input to output */

#include <stdio.h>

int main(void)
{
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}
