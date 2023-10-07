#include "main.h"
#include <stdlib.h>

/**
* main - multiplies two numbers
* @argc: argument count
* @argv: argument vector
* Return: 0 if successful, 98 otherwise
*/
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
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

/**
* is_number - checks if a string is a number
* @s: string to check
* Return: 1 if s is a number, 0 otherwise
*/
int is_number(char *s)
{
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}

/**
* multiply - multiplies two numbers and prints the result
* @num1: first number
* @num2: second number
*/
void multiply(char *num1, char *num2)
{
	/* Your multiplication logic here */
}
