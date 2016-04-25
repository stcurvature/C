/*
 * Write a program to copy its input to its output, replaceing each
 * tab \t, each backspace \b and each backslash by \\. This makes
 * tabs and backspaces visible in unmabigious way
 *
 */

#include <stdio.h>

int main(void)
{

	int c;

	while ((c = getchar()) != EOF) {

		if (c == '\t') {
			putchar('\\');
			putchar('t');
		} else if (c == '\b') {
			putchar('\\');
			putchar('b');
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else {
			putchar(c);
		}
	}
	return 0;
}


