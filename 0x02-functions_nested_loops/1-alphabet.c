#include "main.h"

/**
 * print_alphabet - a function that prints the alphabet,
 * in lowercase, followed by a new line
 * Return: no return.
 */

#include "main.h"

void print_alphabet(void)
{
  char c;

  for (c = 'a'; c <= 'z'; c++)
    {
      _putchar(c);
    }
  _putchar('\n');
}
