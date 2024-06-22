#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of two two-digit numbers,
 *              separated by ", ", in ascending order.
 *              Only putchar function is used, with a maximum of eight uses.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int tens1, ones1, tens2, ones2;

    for (tens1 = 0; tens1 <= 9; tens1++)
    {
        for (ones1 = 0; ones1 <= 9; ones1++)
        {
            for (tens2 = tens1; tens2 <= 9; tens2++)
            {
                /* Initialize ones2 based on the current tens2 */
                ones2 = (tens1 == tens2) ? ones1 + 1 : 0;

                for (; ones2 <= 9; ones2++)
                {
                    putchar(tens1 + '0');
                    putchar(ones1 + '0');
                    putchar(' ');
                    putchar(tens2 + '0');
                    putchar(ones2 + '0');

                    /* Check if it's not the last combination */
                    if (!(tens1 == 9 && ones1 == 9 && tens2 == 9 && ones2 == 9))
                    {
                        putchar(','); /* Print a comma */
                        putchar(' '); /* Print a space */
                    }
                }
            }
        }
    }

    putchar('\n'); /* Print a newline at the end */

    return (0);
}
