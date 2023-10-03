#include "main.h"
#include <stdlib.h>

/**
* argstostr - Concatenates all arguments of your program
* @ac: Argument count
* @av: Argument vector
* Return: pointer to new string, or NULL if fails
*/
char *argstostr(int ac, char **av)
{
	int i, j, k = 0, len = 0;
	char *s;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
		for (j = 0; av[i][j]; j++)
			len++;

	s = malloc(len + ac + 1);
	if (s == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			s[k++] = av[i][j];
		s[k++] = '\n';
	}
	s[k] = '\0';

	return (s);
}
