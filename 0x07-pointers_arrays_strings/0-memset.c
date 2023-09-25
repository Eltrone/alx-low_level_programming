#include "main.h"

/**
*  *_memset - a function that fills memory with a constant byte
*  @s: pointer to put the constant
*  @b: constant
*  @n: max bytes to use
*  Return: pointer s
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int cnt;

	for (cnt = 0; cnt < n; cnt++)
	{
		s[cnt] = b;
	}
	return (s);
}
