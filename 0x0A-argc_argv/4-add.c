#include "main.h"

/**
* main - Add positive numbers
* @argc: Argument count
* @argv: Argument vector
* Return: 0 (Success), 1 (Error)
*/
int main(int argc, char **argv)
{
	int sum = 0;

	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
