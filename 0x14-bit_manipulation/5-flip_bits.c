#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to get from one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits you need to flip to get from n to m.
 */
	unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff;
	unsigned int count;

    /* Calculate the XOR of n and m to get differing bits */
	diff = n ^ m;

	count = 0;
    /* Count the number of set bits in the result */
	while (diff > 0)
	{
	count += diff & 1;  /* Increment count if the rightmost bit is set */
	diff >>= 1;         /* Shift right to check the next bit */
	}

	return (count);
}

