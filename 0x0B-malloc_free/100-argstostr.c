#include "main.h"
#include <stdlib.h>

/**
* create_array - Creates an array of chars, initialized with a specific char.
* @size: The size of the array.
* @c: The character to initialize the array with.
*
* Return: If size == 0 or the function fails - NULL.
*         Otherwise - a pointer to the array.
*/
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *array;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(char) * size);

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
