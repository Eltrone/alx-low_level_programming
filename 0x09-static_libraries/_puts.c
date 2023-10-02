#include "main.h"

/**
* _puts - Outputs a string followed by a new line
* @s: The string to output
*
* Return: void
*/
void _puts(char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}
	_putchar('\n');
}
