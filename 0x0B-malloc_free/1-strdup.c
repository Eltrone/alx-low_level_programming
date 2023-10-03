#include "main.h"
#include <stdlib.h>

char *_strdup(char *str)
{
	int i, len = 0;
	char *new_str;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		new_str[i] = str[i];
	new_str[len] = '\0';

	return (new_str);
}
