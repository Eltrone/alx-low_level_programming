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
	unsigned int cnt;

	for (cnt = 0; n > 0; cnt++, n--)
	{
		s[cnt] = b;
	}
	return (s);
}
