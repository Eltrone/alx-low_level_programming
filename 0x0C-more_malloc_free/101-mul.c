#include "main.h"
#include <stdlib.h>

/**
* main - Entry point, multiplies two numbers
* @argc: Argument count
* @argv: Argument vector
* Return: 0 on success, 98 on error
*/
int main(int argc, char *argv[])
{
	char *num1, *num2, *result;
	int len1, len2, lenr;

	if (argc != 3)
		return (error_exit(NULL));

	num1 = argv[1];
	num2 = argv[2];
	len1 = _strlen(num1);
	len2 = _strlen(num2);
	lenr = len1 + len2 + 1;
	result = malloc(lenr);
	if (!result)
		return (error_exit(NULL));

	initialize_result(result, lenr);
	multiply_numbers(num1, num2, result, len1, len2, lenr);
	print_result(result, lenr);

	free(result);
	return (0);
}

/**
* initialize_result - Initializes the result array
* @result: Result array
* @lenr: Length of the result array
*/
void initialize_result(char *result, int lenr)
{
	int i;

	for (i = 0; i < lenr; i++)
		result[i] = '0';
	result[i] = '\0';
}

/**
* multiply_numbers - Multiplies the numbers and stores in result
* @num1: First number
* @num2: Second number
* @result: Result array
* @len1: Length of num1
* @len2: Length of num2
* @lenr: Length of result
*/
void multiply_numbers(char *num1, char *num2, char *result, int len1, int len2, int lenr)
{
	int i, j, carry, tmp;

	for (i = len1 - 1; i >= 0; i--)
	{
		if (num1[i] < '0' || num1[i] > '9')
			error_exit(result);
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			if (num2[j] < '0' || num2[j] > '9')
				error_exit(result);
			tmp = (num1[i] - '0') * (num2[j] - '0') + carry + (result[i + j + 1] - '0');
			carry = tmp / 10;
			result[i + j + 1] = (tmp % 10) + '0';
		}
		result[i] += carry;
	}
}

/**
* print_result - Prints the result array
* @result: Result array
* @lenr: Length of result array
*/
void print_result(char *result, int lenr)
{
	int i;

	for (i = 0; result[i] == '0' && i < lenr - 1; i++)
		;
	_putchar(result + i);
}

/**
* _strlen - returns the length of a string
* @s: string
* Return: length of string
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
* _putchar - writes the string to stdout
* @str: The string to print
*/
void _putchar(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

/**
* error_exit - exits with status 98 and prints Error
* @result: pointer to free before exiting
* Return: 98
*/
int error_exit(char *result)
{
	free(result);
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}
