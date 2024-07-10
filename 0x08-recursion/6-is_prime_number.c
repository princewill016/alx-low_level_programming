#include "main.h"

/**
 * is_prime_number - Checks if a number is a prime number
 * @n: The number to check
 *
 * Return: 1 if n is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
    int i;

    if (n <= 1)
    {
        return (0); /* n is not a prime number */
    }

    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return (0); /* n is not a prime number */
        }
    }

    return (1); /* n is a prime number */
}
