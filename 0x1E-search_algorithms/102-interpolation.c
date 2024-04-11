#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * interpolation_search - Searches for value in sorted integers array
 * using the Interpolation search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value located, -1 if not present/array NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, pos;
	double fraction;

	if (!array)
		return (-1);

	while (low <= high && value >= array[low] && value <= array[high])
	{
		fraction = (double)(high - low) / (array[high] - array[low]);
		pos = low + (size_t)(fraction * (value - array[low]));

		if (pos >= size)
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			return (-1);
		}

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
		{
			return ((int) pos);
		}
		if (array[pos] < value)
		{
			low = pos + 1;
		} else
		{
			high = pos - 1;
		}
	}

	return (-1);
}
