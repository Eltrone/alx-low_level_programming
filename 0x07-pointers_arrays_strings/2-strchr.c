#include "main.h"

/**
* _strchr - locates a character in a string.
* @s: string to search in
* @c: character to search for
* Return: pointer to the first occurrence of the character c in the string s,
* or NULL if the character is not found
*/
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	// Check for the null character
	if (c == '\0')
	{
		return (s);
	}

	return (NULL);
}
