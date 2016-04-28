/*
 * Write a program to print histogram of the lengths of words in its inputs.
 * It is easy to draw the histogram with bars horizontal;
 * a vertical orientation is more challenging
 *
 */

#include <stdio.h>

#define	TRUE	(1)
#define	FALSE	!(TRUE)

#define	MAX_WORD_LEN	(32)

/* 
 * This array stores the word distribution count 
 * Array index represents the word length
 *
 */

int word_distribution[MAX_WORD_LEN + 1];

/*
 * Known limitation
 *	- period will be added as wordlength
 *
 */

int main(void)
{
	int c;
	int i;
	int wordlen = 0;
	int inword = FALSE;		/* state : not in word */
	int inspace = FALSE;	/* state : not in space */
	int logged = FALSE;		/* state : not yet logged */

	/* init the storage array */
	for (i = 0; i < MAX_WORD_LEN; i++) {
		word_distribution[i] = 0;
	}

	while ((c = getchar()) != EOF) {
	
		/* ignore space, tabs and new lines */
		if ((c == ' ') || (c == '\t') || (c == '\n')) {

			/* mark in space state */
			inspace = TRUE;
			inword = FALSE;

			/* log the word distribution */
			if (!logged) {
				word_distribution[wordlen]++;

				/* rest the state */
				logged = TRUE;
				wordlen = 0;
			} 

		} else {
			/* mark in word state */
			inword = TRUE;
		}

		if (inword) {
			/* increment the word length */
			wordlen++;
			logged = FALSE;
		}
	}

	printf("len - count\n");

	for (i = 0; i < MAX_WORD_LEN; i++) {
		if (word_distribution[i]) {
			printf("%2d : %2d\n", i, word_distribution[i]);
		}
	}

	/* plotting histogram is pending : Need to figure out */

	return 0;
}



