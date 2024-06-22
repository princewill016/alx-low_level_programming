#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: Prints the lowercase alphabet followed by a newline using putchar.
 *              Only putchar function is used, adhering to constraints.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter = 'a';  // Start with 'a'
	while (letter <= 'z')
	{
		putchar(letter);  // Print the current letter
		letter++;         // Move to the next letter
	}
	putchar('\n');  // Print a newline at the end
	return 0;
}
