#include "main.h"
#include <stdio.h>

/**
* print_buffer - Prints a buffer
* @b: The buffer
* @size: The size of the buffer
*/
void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0)
	{
		putchar('\n');
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			if (j + i < size)
				printf("%02x", b[j + i]);
			else
				printf("  ");

			if (j % 2)
				putchar(' ');
		}

		for (j = 0; j < 10 && j + i < size; j++)
		{
			if (b[j + i] >= ' ' && b[j + i] <= '~')
				putchar(b[j + i]);
			else
				putchar('.');
		}

		putchar('\n');
	}
}
