#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* main - Multiplies two positive numbers
* @argc: Number of arguments
* @argv: Array of arguments
*
* Return: 0 on success, 98 on error
*/
int main(int argc, char *argv[])
{
	long num1, num2, product;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atol(argv[1]);
	num2 = atol(argv[2]);

	if (num1 == 0 || num2 == 0)
	{
		printf("Error\n");
		exit(98);
	}

	product = num1 * num2;
	printf("%ld\n", product);

	return (0);
}
