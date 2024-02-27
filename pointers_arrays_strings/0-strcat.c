#include "main.h"
/**
 * _strcat - concatenates 2 strings.
 * @dest: string with concatenation
 * @src: string to be concatenated
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src)
{
	int len1, len2;

	len1 = 0;
	len2 = 0;

	while (*(dest + len1) != '\0')
		len1++;

	while (*(src + len2) != '\0' && len1 < 97)
	{
		*(dest + len1) = *(src + len2);
		len1++;
		len2++;
	}
	*(dest + len1) = '\0';
	return (dest);
}
