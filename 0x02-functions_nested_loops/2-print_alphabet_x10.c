#include "main.h"

/**
 * print_alphabet_x10 -  a function that prints 10 times the alphabet,
 * in lowercase, followed by a new line
 */
void print_alphabet_x10(void)
{
int i, j;

for (j = 0 ; j <= 9 ; j++)
{
for (i = 97 ; i < 123 ; i++)
{
_putchar(i);
}
_putchar('\n');
}
}
