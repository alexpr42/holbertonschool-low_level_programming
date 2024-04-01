#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: A pointer to the number to modify
 * @index: The index of the bit to clear
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	/* Declare variables at the beginning of the function */
	unsigned long int mask;

	/* Check if the index is out of bounds */
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	/* Create a mask with the bit at the specified index set to 0 */
	mask = 1UL << index;

	/* Clear the bit to 0 using the bitwise and operator */
	*n &= ~mask;

	return (1);
}
