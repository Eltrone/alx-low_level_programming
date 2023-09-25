#include "main.h"

/**
*  *_memset - a function that fills memory with a constant byte
*  @n: max bytes use
*  @b: constant
*  @s: pointer to put the constant
*  Return: pointer s
*/

char *_memset(char *s, char b, unsigned int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		s[i] = b;
		i++;
		n--;
	}

	return (s);
}
