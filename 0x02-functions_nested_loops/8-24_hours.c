#include "main.h"

/**
 * print_two_digits - prints a number in two digit format.
 * @n: The number to be printed.
 */
void print_two_digits(int n)
{
    _putchar((n / 10) + '0');
    _putchar((n % 10) + '0');
}

/**
 * jack_bauer - prints every minute of the day of Jack Bauer,
 * starting from 00:00 to 23:59.
 * Return: void
 */
void jack_bauer(void)
{
    int i, j;
    for (i = 0; i <= 23; i++)
    {
        for (j = 0; j <= 59; j++)
        {
            print_two_digits(i);
            _putchar(':');
            print_two_digits(j);
            _putchar('\n');
        }
    }
}
