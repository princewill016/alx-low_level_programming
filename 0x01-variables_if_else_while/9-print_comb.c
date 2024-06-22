#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of single-digit numbers,
 *              separated by ", ", in ascending order.
 *              Only putchar function is used, with a maximum of four uses.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int num;

    for (num = 0; num <= 9; num++)
    {
        putchar(num + '0'); /* Print the current number */
        if (num < 9)
        {
            putchar(','); /* Print a comma */
            putchar(' '); /* Print a space */
        }
    }

    putchar('\n'); /* Print a newline at the end */

    return (0);
}
