#include "main.h"

/**
* _puts - Prints a string followed by a new line to stdout.
* @str: The string to be printed.
*
* Description: Iterates through the string and prints each character.
* Return: None.
*/
void _puts(char *str)
{
	while (*str != '\0')
	{
		putchar(*str + 0);
		str++;
	}
	putchar('\n');
}
