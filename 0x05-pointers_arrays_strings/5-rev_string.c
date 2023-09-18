#include "main.h"
#include <unistd.h>

/**
* rev_string - Reverses a given string.
* @s: Input string.
* Return: None.
*/

void rev_string(char *s)
{
	int x, y;
	char line;

	/*find string length without null char*/
	for (x = 0; s[x] != '\0'; ++x)
		;

	/*swap the string by looping to half the string*/
	for (y = 0; y < x / 2; y++)
	{
		line = s[y];
		s[y] = s[x - 1 - y]; /*-1 because the array starts 0*/
		s[x - 1 - y] = line;
	}
}

