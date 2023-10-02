#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* main - adds positive numbers
* @argc: number of command line arguments
* @argv: array containing the command line arguments
* Return: 0 if no errors, 1 otherwise
*/
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		char *ptr;
		int num = strtol(argv[i], &ptr, 10);

		if (*ptr)
		{
			printf("Error\n");
			return (1);
		}

		sum += num;
	}

	printf("%d\n", sum);
	return (0);
}
