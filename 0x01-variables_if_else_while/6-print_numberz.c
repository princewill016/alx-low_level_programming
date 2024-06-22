#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers of base 10 starting from 0,
 *              followed by a newline. Only putchar function is used.
 *              No variables of type char are used.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int digit;

	for (digit = 0; digit < 10; digit++)
	{
		putchar(digit + '0'); /* Convert digit to character and print */
	}
	putchar('\n'); /* Print a newline at the end */

	return (0);
}
