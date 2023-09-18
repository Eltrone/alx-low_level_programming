#include "main.h"

/**
* _strlen - Returns the length of a string.
* @s: The string to get the length of.
*
* Description: Iterates through the string until it reaches
* the null terminator and counts the number of characters.
* Return: The length of the string.
*/
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
	length++;
        s++;
	}

    return length;
}
