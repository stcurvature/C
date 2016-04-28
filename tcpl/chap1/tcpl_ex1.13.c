/*
 * Write a program to print histogram of the lengths of words in its inputs.
 * It is easy to draw the histogram with bars horizontal;
 * a vertical orientation is more challenging
 *
 */

#include <stdio.h>

#define	TRUE	(1)
#define	FALSE	!(TRUE)

#define	HORIZONTAL_HISTOGRAM (1)
#define VERTICAL_HISTOGRAM (1)

#define	MAX_WORD_LEN	(32)
#define	nline()			printf("\n")


/* 
 * This array stores the word distribution count 
 * Array index represents the word length
 *
 */

int word_distribution[MAX_WORD_LEN + 1];


void plot_line(int count) 
{
	int i = 0;

	for (i = 0; i < MAX_WORD_LEN; i++) {
		if (word_distribution[i] >= count) {
			printf(" *");
		} else {
			printf("  ");
		}
	}
}

void print_magnitude(int count)
{
	while(count--) {
		printf("*");
	}
}

/*
 * Known limitation
 *	- period will be treated as a character
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
	int max_freq = 0;		/* Maximum occurance of a given word length */
	int done = FALSE;		/* Task complete flag */

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


#ifdef	PRINT_REPORT
	printf("len - count\n");
	for (i = 0; i < MAX_WORD_LEN; i++) {
		if (word_distribution[i]) {
			printf("%2d : %2d\n", i, word_distribution[i]);
		}
	}
#endif	/* PRINT_REPORT */

#ifdef	HORIZONTAL_HISTOGRAM
	/* horizontal histogram , vertical histogram needs to be figured out */

	for (i = 0; i < MAX_WORD_LEN; i++) {
			printf("%2d : ", i);
			print_magnitude(word_distribution[i]);
			printf("\n");
	}
#endif	/* HORIZONTAL_HISTOGRAM */

#ifdef	VERTICAL_HISTOGRAM

	/* find the maximum occurance from the given distribution */
	for (i = 0; i < MAX_WORD_LEN; i++) {
		if (word_distribution[i] > max_freq) {
			max_freq = word_distribution[i];
		}
	}


	nline();

	while (!done) {
		printf("%2d : ", max_freq);
		plot_line(max_freq);
	
		nline();

		max_freq -= 1;
		if (max_freq == 0) {
			done = TRUE;
		}
	}

	printf("   :");
	for (i = 0; i < MAX_WORD_LEN; i++) {
		printf(" |");
	}
#endif	/* VERTICAL_HISTOGRAM */

	return 0;
}

