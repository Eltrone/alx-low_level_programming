#include "main.h"

/**
* main - Entry point
* @argc: argument count
* @argv: argument vector
* @return: 0 on success, 98 otherwise
*/
int main(int argc, char *argv[])
{
	char *num1, *num2;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		errors();
		exit(98);
	}
	num1 = argv[1];
	num2 = argv[2];
	multiply(num1, num2);
	return (0);
}

/**
* errors - Print an error message to stdout
*/
void errors(void)
{
	char *err = "Error";

	while (*err)
		_putchar(*err++);
	_putchar('\n');
}

/**
* is_digit - Check if string s consists of digits only
* @s: string to be checked
* @return: 1 if s consists of digits, 0 otherwise
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
* multiply - Multiply two numbers and print the result
* @num1: first number
* @num2: second number
*/
void multiply(char *num1, char *num2)
{
	int len1, len2, *result, i, j, carry, temp;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result = (int *)malloc((len1 + len2) * sizeof(int));
	if (!result)
	{
		errors();
		exit(98);
	}
	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			temp = (num1[i] - '0') * (num2[j] - '0') + carry + result[i + j + 1];
			carry = temp / 10;
			result[i + j + 1] = temp % 10;
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
* _strlen - Calculate the length of a string
* @s: the string
* @return: length of the string
*/
int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
