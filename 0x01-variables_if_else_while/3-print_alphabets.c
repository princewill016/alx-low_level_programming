#include <stdio.h>

/**
 * main - Entry point
 *
 * Description:
 * Prints the lowercase alphabet followed by the uppercase alphabet, then a newline.
 * Only putchar function is used, adhering to constraints.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	/* Print lowercase alphabet */
	for (letter = 'a'; letter <= 'z'; letter++)
	{
		putchar(letter);
	}

	/* Print uppercase alphabet */
	for (letter = 'A'; letter <= 'Z'; letter++)
	{
		putchar(letter);
	}

	putchar('\n');  /* Print newline */

	return 0;
}
