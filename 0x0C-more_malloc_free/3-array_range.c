#include "main.h"
#include <stdlib.h>

/**
* array_range - Creates an array of integers
* @min: Minimum integer
* @max: Maximum integer
* 
* Return: Pointer to the newly created array
*/
int *array_range(int min, int max)
{
	int *arr;
	int i, len;

	if (min > max)
		return (NULL);

	len = max - min + 1;

	arr = malloc(len * sizeof(int));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < len; i++, min++)
		arr[i] = min;

	return (arr);
}
