#include "main.h"

/**
* _strstr - Finds the first occurrence of the substring needle in the string haystack.
* @haystack: The string in which to search for needle.
* @needle: The substring to find.
*
* Return: A pointer to the beginning of the located substring,
*         or NULL if the substring is not found.
*/
char *_strstr(char *haystack, char *needle)
{
	int i, j, start;

	for (i = 0; haystack[i]; i++)
	{
		for (start = i, j = 0; needle[j]; j++, start++)
		{
			if (haystack[start] != needle[j] || !haystack[start])
				break;
		}
		if (!needle[j])
			return (haystack + i);
	}

	return (0);
}
