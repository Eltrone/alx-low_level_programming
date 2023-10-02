#include "main.h"

/**
* _strspn - Gets the length of a prefix substring.
* @s: The string to be scanned.
* @accept: The characters to be searched for.
*
* Return: The length of the initial segment of `s` which consists only of bytes in `accept`.
*/
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, flag;

	for (i = 0; s[i]; i++)
	{
		for (flag = 0, j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			return (i);
	}

	return (i);
}
