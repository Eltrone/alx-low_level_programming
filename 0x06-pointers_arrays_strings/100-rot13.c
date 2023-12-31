#include "main.h"

/**
* rot13 - Encodes a string using rot13
* @s: The string to be encoded
*
* Return: A pointer to the encoded string
*/
char *rot13(char *s)
{
	int i = 0, j;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (s[i])
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == input[j])
			{
				s[i] = output[j];
				break;
			}
		}
		i++;
	}

	return (s);
}
