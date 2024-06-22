#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all the numbers of base 16 in lowercase,
 *              followed by a newline. Only putchar function is used.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int num;
    char letter;

    for (num = 0; num < 10; num++)
    {
        putchar(num + '0'); /* Print numbers 0-9 */
    }

    for (letter = 'a'; letter <= 'f'; letter++)
    {
        putchar(letter); /* Print letters a-f */
    }

    putchar('\n'); /* Print a newline at the end */

    return (0);
}
