#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible different combinations of three digits,
 *              separated by ", ", in ascending order.
 *              Only putchar function is used, with a maximum of six uses.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int hundreds_digit, tens_digit, ones_digit;

    for (hundreds_digit = 0; hundreds_digit <= 7; hundreds_digit++)
    {
        for (tens_digit = hundreds_digit + 1; tens_digit <= 8; tens_digit++)
        {
            for (ones_digit = tens_digit + 1; ones_digit <= 9; ones_digit++)
            {
                putchar(hundreds_digit + '0'); /* Print hundreds digit */
                putchar(tens_digit + '0');     /* Print tens digit */
                putchar(ones_digit + '0');     /* Print ones digit */

                /* Check if it's not the last combination */
                if (!(hundreds_digit == 7 && tens_digit == 8 && ones_digit == 9))
                {
                    putchar(','); /* Print a comma */
                    putchar(' '); /* Print a space */
                }
            }
        }
    }

    putchar('\n'); /* Print a newline at the end */

    return (0);
}
