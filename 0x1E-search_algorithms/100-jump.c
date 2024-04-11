#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where value is located,
 * or -1 if value is not present in array or if array is NULL
 */

int jump_search(int *array, size_t size, int value)
{
    size_t jump = sqrt(size);
    size_t prev = 0;
    size_t left, right, i;

    if (!array)
        return (-1);

    while (prev < size && array[prev] < value)
    {
        printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
        prev += jump;
    }

    left = prev < jump ? 0 : prev - jump;
 
    
    right = (prev < size) ? prev : prev - 1;

    
    
    printf("Value found between indexes [%ld] and [%ld]\n", left, (prev < size) ? right : prev);

    right = min(size - 1, right);
    for (i = left; i <= right; ++i)
    {
        printf("Value checked array[%ld] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return (int)i;
    }

    return (-1);
}

/**
 * min - Calculates the minimum of two size_t values
 * @a: first value
 * @b: second value
 * Return: the smaller of a and b
 */
size_t min(size_t a, size_t b)
{
    return (a < b) ? a : b;
}
