#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
* is_digit - Evaluates if the string contains only digits
* @s: The string to be checked
*
* Return: 0 if a non-digit character is found, 1 otherwise
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
* _strlen - Calculates the length of a string
* @s: The string to be evaluated
*
* Return: Length of the string
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
* errors - Handles errors for the main function
*/
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
* multiply_and_print - Performs multiplication of two strings and prints result
* @s1: First number as a string
* @s2: Second number as a string
*/
void multiply_and_print(char *s1, char *s2)
{
	int len1, len2, len, i, *result, a = 0, carry = 0, digit1, digit2;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		exit(1);

	for (i = 0; i < len; i++)
		result[i] = 0;

	for (int i = len1 - 1; i >= 0; i--)
	{
		digit1 = s1[i] - '0';
		carry = 0;
		for (int j = len2 - 1; j >= 0; j--)
		{
			digit2 = s2[j] - '0';
			carry += result[i + j + 1] + (digit1 * digit2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[i] += carry;
	}

	for (i = 0; i < len; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			putchar(result[i] + '0');
	}
	if (!a)
		putchar('0');
	putchar('\n');
	free(result);
}

/**
* main - Multiplies two positive numbers
* @argc: Argument count
* @argv: Argument array
*
* Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
	char *s1, *s2;

	if (argc != 3)
		errors();

	s1 = argv[1];
	s2 = argv[2];

	if (!is_digit(s1) || !is_digit(s2))
		errors();

	multiply_and_print(s1, s2);
	return (0);
}
