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
    int num1_tens, num1_ones, num2_tens, num2_ones;

    for (num1_tens = 0; num1_tens <= 9; num1_tens++)
    {
        for (num1_ones = 0; num1_ones <= 9; num1_ones++)
        {
            for (num2_tens = num1_tens; num2_tens <= 9; num2_tens++)
            {
                int start_ones = (num2_tens == num1_tens) ? num1_ones + 1 : 0;

                for (num2_ones = start_ones; num2_ones <= 9; num2_ones++)
                {
                    // Printing first two-digit number
                    putchar(num1_tens + '0');
                    putchar(num1_ones + '0');
                    putchar(' ');

                    // Printing second two-digit number
                    putchar(num2_tens + '0');
                    putchar(num2_ones + '0');

                    // Adding comma and space if not the last combination
                    if (!(num1_tens == 9 && num1_ones == 9 && num2_tens == 9 && num2_ones == 9))
                    {
                        putchar(',');
                        putchar(' ');
                    }
                }
            }
        }
    }

    putchar('\n');

    return (0);
}
