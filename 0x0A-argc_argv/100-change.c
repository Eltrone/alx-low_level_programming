#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* main - Program to return minimum number of coins for change.
* @argc: Argument count.
* @argv: Argument vector.
* Return: 0 if successful, 1 otherwise.
*/
int main(int argc, char *argv[])
{
	int cents, coins = 0;

	/* Check the number of arguments */
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	/* Check for negative input */
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	/* Calculate minimum number of coins */
	coins += cents / 25;
	cents %= 25;
	coins += cents / 10;
	cents %= 10;
	coins += cents / 5;
	cents %= 5;
	coins += cents / 2;
	cents %= 2;
	coins += cents;

	printf("%d\n", coins);
	return (0);
}
