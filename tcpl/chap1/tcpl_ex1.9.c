/*
 * Exercise 1.9 Write a program to copy its input to its output, replace each
 * string of one or more blanks by a single blank
 *
 */


#include <stdio.h>

int main(void)
{
	int c;
	int inspace = 0;

	while ((c = getchar()) != EOF) {

		if ((c == ' ') && (inspace == 0)) {
			inspace = 1;
			putchar(c);
		} else if ((c == ' ') && (inspace == 1)) {
			/* do nothing */
		} else {
			putchar(c);
			inspace = 0;
		}
	}
}

