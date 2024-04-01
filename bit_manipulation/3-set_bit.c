#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index
 * @n: A pointer to the number to modify
 * @index: The index of the bit to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	/* Declaration of the mask variable */
	unsigned long int mask;

	/* Check if the index is out of bounds */
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	/* Create a mask with the bit at the specified index set to 1 */
	mask = 1UL << index;

	/* Set the bit to 1 using the bitwise OR operator */
	*n |= mask;

	return (1);
}
