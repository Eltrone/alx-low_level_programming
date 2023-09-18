#include "main.h"

/**
* print_rev - Prints a string in reverse followed by a new line.
* @s: The string to be printed in reverse.
*
* Description: Iterates to the end of the string and then
* prints each character in reverse order.
* Return: None.
*/

void print_rev(char *s)
{
    int length = 0;

    /* Find the end of the string */
    while (s[length] != '\0')
    {
        length++;
    }

    /* Print the string in reverse */
    for (int i = length - 1; i >= 0; i--)
    {
        _putchar(s[i]);
    }
    _putchar('\n');
}
