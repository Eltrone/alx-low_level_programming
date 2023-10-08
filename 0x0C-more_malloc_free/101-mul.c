#include "main.h"

/**
* main - multiplies two large numbers
* @argc: Argument count
* @argv: Argument vector
* Return: 0 on success, 98 on failure
*/
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		errors();
		exit(98);
	}
	multiply(argv[1], argv[2]);
	return (0);
}

/**
* errors - prints "Error" followed by a new line to stdout
*/
void errors(void)
{
	char *err = "Error";

	while (*err)
		_putchar(*err++);
	_putchar('\n');
}

/**
* is_digit - Checks if a string only contains digits
* @s: String to check
* Return: 1 if all digits, 0 otherwise
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
* multiply - Multiplies two large numbers
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
* _strlen - Calculates the length of a string
* @s: String to calculate the length of
* Return: Length of string
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
