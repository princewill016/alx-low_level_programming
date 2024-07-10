#include "main.h"

/**
 * is_prime_number - Checks if a number is a prime number
 * @n: The number to check
 *
 * Return: 1 if n is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
    return (is_prime_helper(n, 2));
}

/**
 * is_prime_helper - Helper function to check if a number is prime recursively
 * @n: The number to check
 * @i: The current divisor to check if n is divisible by
 *
 * Return: 1 if n is a
