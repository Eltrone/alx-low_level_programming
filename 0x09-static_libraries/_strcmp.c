#include "main.h"

/**
* _strcmp - Compares two strings s1 and s2.
* @s1: The first string to be compared.
* @s2: The second string to be compared.
*
* Return: negative integer if s1 < s2,
*         zero if s1 = s2,
*         positive integer if s1 > s2.
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return *(unsigned char *)s1 - *(unsigned char *)s2;
}
