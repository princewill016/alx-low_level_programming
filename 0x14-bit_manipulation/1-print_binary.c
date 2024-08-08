#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
    unsigned long int mask;
    int leading_zero = 1;

    /* Start with the highest bit position */
    mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

    while (mask > 0)
    {
        /* Check if the current bit is set */
        if (n & mask)
        {
            _putchar('1');
            leading_zero = 0;
        }
        else if (!leading_zero)
        {
            _putchar('0');
        }
        mask >>= 1;
    }

    /* If all bits are zero, print '0' */
    if (leading_zero)
    {
        _putchar('0');
    }
}

