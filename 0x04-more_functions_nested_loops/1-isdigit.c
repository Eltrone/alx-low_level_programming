#include "main.h"

/**
 * _isdigit – a function that checks if the character is a digit
 * 
 * @c: the input
 * 
 * Return: 1 if c is a digit, 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

