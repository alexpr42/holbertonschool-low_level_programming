#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to get from n to m
 * @n: The first number
 * @m: The second number
 *
 * Return: The number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;
	unsigned int count = 0;

	/* Count the number of set bits in the XOR result */
	while (diff > 0)
	{
		count += diff & 1;
		diff >>= 1;
	}

	return (count);
}
