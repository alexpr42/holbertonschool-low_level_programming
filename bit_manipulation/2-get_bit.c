#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 * @n: The number to extract the bit from
 * @index: The index of the bit to extract
 *
 * Return: The value of the bit at the given index, or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	/* Check if index is greater than the num of bits in an unsigned int */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* Shift n to the right by index bits and then bitwise AND it with 1 */
	return ((n >> index) & 1);
}
