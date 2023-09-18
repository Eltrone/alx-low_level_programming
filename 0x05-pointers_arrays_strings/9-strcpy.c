#include "main.h"

/**
* _strcpy - Copies the string from 'src' to 'dest', including the null byte.
* @dest: Destination string.
* @src: Source string.
* Return: Pointer to 'dest'.
*/

char *_strcpy(char *dest, char *src)
{
	int x = -1;

	do {
		x++;
		dest[x] = src[x];
	} while (src[x] != '\0');

	return (dest);
}
