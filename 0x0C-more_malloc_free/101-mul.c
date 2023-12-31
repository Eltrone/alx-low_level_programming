#include "main.h"
#include <stdlib.h>

/**
* is_digit - checks if a string contains a non-digit char
* @s: string to be evaluated
*
* Return: 0 if a non-digit is found, 1 otherwise
*/
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
* _strlen - returns the length of a string
* @s: string to evaluate
*
* Return: the length of the string
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
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
* multiply - multiplies two strings of digits
* @s1: first string
* @s2: second string
* @result: array to store the result
*/
void multiply(char *s1, char *s2, int *result)
{
	int len1 = _strlen(s1);
	int len2 = _strlen(s2);
	int carry, digit1, digit2;

	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = s1[len1] - '0';
		carry = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			digit2 = s2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
}


/**
* main - multiplies two positive numbers
* @argc: number of arguments
* @argv: array of arguments
*
* Return: always 0 (Success)
*/
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, i, *result, a = 0;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		errors();
	s1 = argv[1];
	s2 = argv[2];
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;

	multiply(s1, s2, result);

	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}

