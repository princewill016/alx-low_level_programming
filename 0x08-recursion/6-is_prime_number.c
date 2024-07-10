#include "main.h"

/**
 * is_prime_number - Checks if a number is a prime number
 * @n: The number to check
 *
 * Return: 1 if n is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
    /* Edge cases */
    if (n <= 1)
    {
        return (0); /* n is not a prime number */
    }
    
    /* Helper function declaration */
    return (is_prime_helper(n, 2));
}

/**
 * is_prime_helper - Helper function to check if a number is prime recursively
 * @n: The number to check
 * @i: The current divisor to check if n is divisible by
 *
 * Return: 1 if n is a prime number, 0 otherwise
 */
int is_prime_helper(int n, int i)
{
    if (i * i > n)
    {
        return (1); /* n is a prime number */
    }
    if (n % i == 0)
    {
        return (0); /* n is not a prime number */
    }
    return (is_prime_helper(n, i + 1));
}
