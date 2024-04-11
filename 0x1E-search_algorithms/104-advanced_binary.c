#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Helper function to print the current subarray
 * @array: Pointer to the element to start printing from
 * @size: Number of elements to print
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}


/**
 * recursive_binary_search - Helper function perform binary search recursively
 * @array: Pointer to the first element of the array to search in
 * @left: Left index of the subarray to search
 * @right: Right index of the subarray to search
 * @value: The value to search for
 * Return: The first index where value is located or -1
 */
int recursive_binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (right >= left)
	{
		print_array(array + left, right - left + 1);
		mid = left + (right - left) / 2;
		if (array[mid] == value)
		{
			if (mid != left && array[mid - 1] == value)
				return (recursive_binary_search(array, left, mid, value));
			return ((int)mid);
		}
		if (array[mid] < value)
			return (recursive_binary_search(array, mid + 1, right, value));
		else
			return (recursive_binary_search(array, left, mid - 1, value));
	}
	return (-1);
}


/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * using an advanced binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: First index value is located, or -1 if not present/array is NULL
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);
	return (recursive_binary_search(array, 0, size - 1, value));
}
