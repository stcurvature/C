/* count blanks, tabs, and new lines */

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

		if (c == '\t') {
			++newlines;
		}
	}

	printf ("blanks : %d\ntabs : %d\nnew lines : %d\n\n", blanks, tabs, newlines);
	return 0;
}

