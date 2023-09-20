#include "main.h"

/**
*_strcmp - Compares two strings
*@s1: First string
*@s2: Second string
*
*Return: 
* 0 if s1 and s2 are equal
* A positive value if s1 > s2
* A negative value if s1 < s2
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (int)(*s1) - (int)(*s2);
}
