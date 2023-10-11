#include "function_pointers.h"

/**
* int_index - Searches for an integer in an array
* @array: The array
* @size: The size of the array
* @cmp: The comparison function
*
* Return: The index of the first match, or -1 if not found
*/
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}
	return (-1);
}
