#include "main.h"

/**
*_strncat - Concatenates two strings using at most n bytes from src
*@dest: The destination string
*@src: The source string
*@n: Maximum number of bytes to be used from src
*
*Return: A pointer to the resulting string dest
*/
char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest;
	int i = 0;

	while (*ptr)
		ptr++;

	while (i < n && src[i])
	{
		*ptr = src[i];
		ptr++;
		i++;
	}

	if (i < n)
		*ptr = '\0';

	return dest;
}
