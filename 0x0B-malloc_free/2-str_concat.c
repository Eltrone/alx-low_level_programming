#include "main.h"
#include <stdlib.h>

/**
* str_concat - Concatenates two strings.
* @s1: The first string.
* @s2: The second string.
*
* Return: If s1 == NULL, s2 == NULL, or the function fails - NULL.
*         Otherwise - a pointer to the concatenated space in memory.
*/
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int i, j, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i]; i++)
		len1++;
	for (i = 0; s2[i]; i++)
		len2++;

	concat = malloc(sizeof(char) * (len1 + len2 + 1));

	if (concat == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		concat[i] = s1[i];
	for (j = 0; s2[j]; j++)
		concat[i + j] = s2[j];

	concat[len1 + len2] = '\0';

	return (concat);
}
