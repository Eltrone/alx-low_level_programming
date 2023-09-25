#include "main.h"

/**
*  *_strchr - a function that locates a character in a string.
*
*  @s: pointer to put the constant
*  @c: constant
*
*  Return: pointer to s
*/

char *_strchr(char *s, char c)

{
	int cnt;

	for (cnt = 0; s[cnt] >= '\0' ; cnt++)
	{
		if (s[cnt] == c)
		{
			return (s + cnt);
		}
	}

	return ('\0');
}
