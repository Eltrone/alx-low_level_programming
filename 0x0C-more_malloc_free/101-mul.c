#include "main.h"
#include <stdlib.h>

/**
* is_digit - checks if a string contains a non-digit char
* @s: string to be evaluated
* Return: 0 if a non-digit is found, 1 otherwise
*/
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
		if (s[i] < '0' || s[i++] > '9')
			return (0);
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

	while (s[i])
		i++;
	return (i);
}

/**
* errors - handles errors for main
*/
void errors(void)
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
* main - multiplies two positive numbers
* @argc: number of arguments
* @argv: array of arguments
* Return: always 0 (Success)
*/
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, len, i, j, carry, *result, flag = 0;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		errors();
	num1 = argv[1], num2 = argv[2];
	len1 = _strlen(num1), len2 = _strlen(num2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		errors();
	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			carry += result[i + j + 1] + ((num1[i] - '0') * (num2[j] - '0'));
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry)
			result[i + j + 1] += carry;
	}
	for (i = 0; i < len - 1; i++)
		if (result[i])
			flag = 1, _putchar(result[i] + '0');
	if (!flag)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
