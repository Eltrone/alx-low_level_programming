#include "main.h"

/**
 * print_numbers - Displays numbers from 0 to 9.
 * This function limits the use of _putchar to two calls.
 * 
 * Return: None.
 */
void print_numbers(void)
{
    int i;

    for (i = 0; i <= 9; i++)
    {
        _putchar(i + '0');
    }
    _putchar('\n');
}
