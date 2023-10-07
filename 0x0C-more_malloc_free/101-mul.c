#include "main.h"
#include <stdlib.h>

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
* _putchar - Writes a character to stdout
* @c: The character to print
* Return: 1 on success, -1 on failure
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
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
* main - Multiplies two numbers
* @argc: Argument count
* @argv: Argument vector
* Return: 0 if successful, 98 otherwise
*/
int main(int argc, char *argv[])
{
	long long num1, num2, result;

	if (argc != 3)
		print_error();

	if (!is_number(argv[1]) || !is_number(argv[2]))
		print_error();

	num1 = atoll(argv[1]);
	num2 = atoll(argv[2]);
	result = num1 * num2;

	printf("%lld\n", result);

	return (0);
}
