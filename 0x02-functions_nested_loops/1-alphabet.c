#include "main.h"

/**
 * print_alphabet - Prints the alphabet in lowercase followed by a newline.
 */
void print_alphabet(void)
{
	char letter = 'a'; /* Initialize 'letter' to 'a' */

	while (letter <= 'z') /* Loop through 'a' to 'z' */
	{
		_putchar(letter); /* Print the current letter */
		letter++; /* Move to the next letter */
	}
	_putchar('\n'); /* Print a newline at the end */
}

