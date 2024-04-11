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
    size_t step = jump;

    if (!array)
        return (-1);

    /* Finding the block where element is present (if it is present) */
    while (array[min(step, size) - 1] < value)
    {
        printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
        prev = step;
        step += jump;
        if (prev >= size)
            return (-1);
    }

    /* Doing a linear search for value in block beginning with prev */
    printf("Value found between indexes [%ld] and [%ld]\n", prev, step);
    while (array[prev] < value)
    {
        printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
        prev++;
        if (prev == min(step, size))
            return (-1);
    }

    /* If element is found */
    if (array[prev] == value)
    {
        printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
        return prev;
    }

    return (-1);
}

/**
 * min - Returns the minimum of two size_t values
 * @a: The first value
 * @b: The second value
 *
 * Return: The minimum value
 */
size_t min(size_t a, size_t b)
{
    return (a < b) ? a : b;
}
