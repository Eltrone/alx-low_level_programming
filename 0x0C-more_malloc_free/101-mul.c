#include "main.h"
#include <stdlib.h>

int is_number(char *s);
void print_error(void);
void _putchar(char c);
void multiply(char *num1, char *num2);

/**
* main - Entry point, multiplies two numbers
* @argc: Argument count
* @argv: Argument vector
* Return: 0 if successful, 98 otherwise
*/
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
		print_error();

	multiply(argv[1], argv[2]);

	return (0);
}

/**
* is_number - Checks if a string is a number
* @s: The string to check
* Return: 1 if the string is a number, 0 otherwise
*/
int is_number(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
* print_error - Prints an error message and exits
*/
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
* _putchar - Writes a character to stdout
* @c: The character to print
*/
void _putchar(char c)
{
	write(1, &c, 1);
}

/**
* multiply - Multiplies two numbers and prints the result
* @num1: The first number
* @num2: The second number
*/
void multiply(char *num1, char *num2)
{
	int len1, len2, carry, sum, i, j;
	int *result;

	len1 = strlen(num1);
	len2 = strlen(num2);

	result = calloc(len1 + len2, sizeof(int));
	if (!result)
		print_error();

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			sum = (num1[i] - '0') * (num2[j] - '0') + carry + result[i + j + 1];
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
