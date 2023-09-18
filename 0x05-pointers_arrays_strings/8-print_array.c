#include "main.h"

/**
* print_array - Prints n elements of an integer array.
* @a: Array of integers.
* @n: Number of elements to print.
* Return: None.
*/
void print_array(int *a, int n)
{
	int x;

	for (x = 0; x < n; x++)
	{
		if (x != (n - 1))
			printf("%d, ", a[x]);
		else
			printf("%d", a[x]);
	}
	printf("\n");
}
