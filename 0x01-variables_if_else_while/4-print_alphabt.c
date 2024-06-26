#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the lowercase alphabet followed by a newline,
 *              excluding the letters 'q' and 'e', using putchar.
 *              Only putchar function is used, adhering to constraints.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter = 'a'; /* Start with 'a' */

	while (letter <= 'z')
	{
		if (letter != 'q' && letter != 'e')
		{
			putchar(letter); /* Print the current letter */
		}
		letter++; /* Move to the next letter */
	}

	putchar('\n'); /* Print a newline at the end */

	return (0);
}
