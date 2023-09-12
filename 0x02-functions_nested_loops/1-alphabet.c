#include "main.h"

/**
 * print_alphabet - a function that prints the alphabet,
 * in lowercase, followed by a new line
 * Return: no return.
 */

void print_alphabet(void)
{
	int i = 97;

	for (i = 97 ; i < 123 ; i++)
	{
		_putchar(i);
	}
	_putchar('\n');
}
