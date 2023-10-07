#include "main.h"
#include <stdlib.h>

/**
* is_digit - Check if a string is composed of digits.
* @str: The input string.
* Return: 1 if composed of digits, 0 otherwise.
*/
int is_digit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
* main - Entry point
* @argc: The number of command-line arguments.
* @argv: An array of command-line argument strings.
* Return: 0 if successful, 98 if incorrect arguments or input not composed of digits.
*/
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	char *num1 = argv[1];
	char *num2 = argv[2];
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len_result = len1 + len2;
	int *result = calloc(len_result, sizeof(int));

	if (result == NULL)
	{
		printf("Error\n");
		return (98);
	}

	/* Multiply the numbers */
	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			int product = (num1[i] - '0') * (num2[j] - '0');
			int sum = result[i + j + 1] + product;
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	/* Skip leading zeros in the result */
	int i = 0;
	while (i < len_result - 1 && result[i] == 0)
		i++;

	/* Print the result */
	while (i < len_result)
	{
		_putchar(result[i] + '0');
		i++;
	}
	_putchar('\n');

	free(result);
	return (0);
}
