#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * print_array - Helper function to print array between two indices.
 * @array: The array to be printed.
 * @left: The starting index of the range to print.
 * @right: The ending index of the range to print.
 */
void print_array(int *array, size_t left, size_t right)
{
    printf("Searching in array: ");
    while (left <= right)
    {
        printf("%d", array[left]);
        if (left < right)
            printf(", ");
        left++;
    }
    printf("\n");
}

/**
 * binary_search - Performs binary search on a subarray
 * @array: Pointer to the first element of the array to search
 * @left: Left boundary of the subarray to search
 * @right: Right boundary of the subarray to search
 * @value: The value to search for
 * Return: The first index where value is located, or -1 if not present
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
    size_t mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        print_array(array, left, right);
        if (array[mid] == value)
            return (int)mid;
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located, or -1 if not present or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t index = 1;
    if (!array)
        return (-1);
    if (array[0] == value)
        return 0;

    while (index < size && array[index] <= value)
    {
        printf("Value checked array[%lu] = [%d]\n", index, array[index]);
        index *= 2;
    }

    return binary_search(array, index / 2, min(index, size - 1), value);
}

/**
 * min - Find the minimum of two values
 * @a: first number
 * @b: second number
 * Return: the smaller of a and b
 */
size_t min(size_t a, size_t b)
{
    return (a < b) ? a : b;
}

