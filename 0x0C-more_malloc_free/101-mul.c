#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#define ERR_MSG "Error"

/**
* main - Entry point, multiplies two numbers
* @argc: Argument count
* @argv: Argument vector
* Return: 0 if successful, 98 otherwise
*/
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, len, i, carry, digit1, digit2, *result, flag = 0;

	num1 = argv[1];
	num2 = argv[2];

	if (argc != 3 || !is_digit(num1) || !is_digit(num2))
		errors();

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2 + 1;

	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);

	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;

	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = num1[len1] - '0';
		carry = 0;

		for (len2 = _strlen(num2) - 1; len2 >= 0; len2--)
		{
			digit2 = num2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}

		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}

	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			flag = 1;
		if (flag)
			_putchar(result[i] + '0');
	}

	if (!flag)
		_putchar('0');

	_putchar('\n');
	free(result);
	return (0);
}

/**
* is_digit - Checks if a string is a number
* @s: The string to check
* Return: 1 if the string is a number, 0 otherwise
*/
int is_digit(char *s)
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
* _strlen - returns the length of a string
* @s: string to evaluate
* Return: the length of the string
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
* errors - handles errors for main
*/
void errors(void)
{
	printf("Error\n");
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
