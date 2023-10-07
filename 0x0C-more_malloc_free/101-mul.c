#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*/
void _putchar(char c)
{
	write(1, &c, 1);
}

/**
* is_digit - checks if a string is a digit
* @str: string to check
* Return: 1 if all characters are digits, 0 otherwise
*/
int is_digit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
* multiply - multiplies two numbers and prints the result
* @num1: first number as a string
* @num2: second number as a string
*/
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j;
	int *result;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result = malloc((len1 + len2) * sizeof(int));
	if (!result)
		exit(98);

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			int n2 = num2[j] - '0';
			int sum = n1 * n2 + result[i + j + 1] + carry;

			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i] += carry;
	}

	for (i = 0; i < len1 + len2; i++)
	{
		if (i == 0 && result[i] == 0)
			continue;
		_putchar(result[i] + '0');
	}
	_putchar('\n');

	free(result);
}

/**
* main - Entry point, multiplies two numbers
* @argc: Argument count
* @argv: Argument vector
* Return: 0 on success, 98 on error
*/
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}
	if (!is_digit(argv[1]) || !is_digit(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}
	multiply(argv[1], argv[2]);
	return (0);
}
