#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array and initializes with specific character
 * @size: is the size of the array
 * @c: character with the one to be initialized
 *
 * Return: a pointer to the to the created array, NULL if it fails
 */

char *create_array(unsigned int size, char c)
{
	char *ptr;
	int i = 0;

	if (size == 0)
		return (NULL);

	ptr = malloc(sizeof(char) * size);

	if (ptr == NULL)
		return (NULL);

	while (size--)
	{
		ptr[i++] = c;
	}

	return (ptr);
}
