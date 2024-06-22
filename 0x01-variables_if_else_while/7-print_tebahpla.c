#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the lowercase alphabet in reverse,
 *              followed by a newline. Only putchar function is used.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	for (letter = 'z'; letter >= 'a'; letter--)
	{
		putchar(letter); /* Print the current letter */
	}
		putchar('\n'); /* Print a newline at the end */

	return (0);
}
