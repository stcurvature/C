/*
 * Exercise 1.8 - Write a program to count blanks, tabs and newlines
 *
 */

#include <stdio.h>

int main(void)
{
	int blanks = 0;
	int tabs = 0;
	int newlines = 0;
	int c;

	while ((c = getchar()) != EOF) {
		
		if (c == ' ') {
			++blanks;
		}

		if (c == '\t') {
			++tabs;
		}

		if (c == '\n') {
			++newlines;
		}
	}

	printf ("blanks : %d\ntabs : %d\nnew lines : %d\n\n", blanks, tabs, newlines);
	return 0;
}

