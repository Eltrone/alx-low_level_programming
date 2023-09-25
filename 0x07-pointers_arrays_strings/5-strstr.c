#include "main.h"

/**
* _strstr - locates a substring.
* @haystack: string to search in
* @needle: substring to search for
* Return: pointer to the beginning of the located substring,
* or NULL if the substring is not found
*/
char *_strstr(char *haystack, char *needle)
{
	int i, j, start;

	for (i = 0; haystack[i]; i++)
	{
		start = i;
		for (j = 0; needle[j]; j++)
		{
			if (haystack[i + j] != needle[j] || !haystack[i + j])
			{
				break;
			}
		}
		if (!needle[j])
		{
			return (haystack + start);
		}
	}

	return (NULL);
}
