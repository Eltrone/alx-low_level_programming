#include "main.h"

/**
* leet - Encodes a string into 1337
* @s: The string to be encoded
*
* Return: A pointer to the encoded string
*/
char *leet(char *s)
{
	int i = 0, j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	while (s[i])
	{
		for (j = 0; j < 10; j++)
		{
			if (s[i] == letters[j])
			{
				s[i] = numbers[j];
				break;
			}
		}
		i++;
	}

	return s;
}
