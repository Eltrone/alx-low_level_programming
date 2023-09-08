#include <stdio.h>

/**
 * main - program that prints the lowercase alphabet in reverse,
 * followed by a new line
 * description: 'Smile in the mirror'
 * Return: always 0
 */

int main(void)
{
int n = 122;

while (n >= 97)
{
putchar(n);
n--;
}
putchar('\n');
return (0);
}
