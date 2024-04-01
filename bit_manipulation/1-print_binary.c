#include "main.h"

/**
 * print_binary_recursive - Recursively print binary representation of a number
 * @n: Number to convert to binary
 */
void print_binary_recursive(unsigned long int n)
{
	if (n == 0)
		return;

	print_binary_recursive(n >> 1);
	_putchar((n & 1) + '0');
}

/**
 * print_binary - Print binary representation of a number
 * @n: Number to convert to binary
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	print_binary_recursive(n);
}
