#include "main.h"

/**
* _strcpy - Copies the string from src to dest
* @dest: The destination for the copied string
* @src: The source of the string to be copied
*
* Return: A pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return dest;
}
