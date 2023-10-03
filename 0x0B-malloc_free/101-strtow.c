#include "main.h"
#include <stdlib.h>

/**
 * wordcount - Count the number of words in a string
 * @str: The string to count
 * Return: The number of words in the string
 */
int wordcount(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
		if ((str[i] != ' ' && str[i + 1] == ' ') || (str[i] != ' ' && str[i + 1] == '\0'))
			count++;
	return (count);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 * Return: Pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	int i, j, k, l, wcount;
	char **s;

	if (str == NULL || *str == '\0')
		return (NULL);

	wcount = wordcount(str);
	if (wcount == 0)
		return (NULL);

	s = malloc((wcount + 1) * sizeof(char *));
	if (s == NULL)
		return (NULL);

	for (i = 0, k = 0; i < wcount; i++)
	{
		while (str[k] == ' ')
			k++;
		for (j = k; str[j] != ' ' && str[j] != '\0'; j++)
			;
		s[i] = malloc((j - k + 1) * sizeof(char));
		if (s[i] == NULL)
		{
			while (i >= 0)
				free(s[--i]);
			free(s);
			return (NULL);
		}
		for (l = 0; k < j; k++, l++)
			s[i][l] = str[k];
		s[i][l] = '\0';
	}
	s[i] = NULL;
	return (s);
}
