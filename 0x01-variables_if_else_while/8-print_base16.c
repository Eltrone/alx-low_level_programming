#include <stdio.h>

/**
 * main - program that prints the lowercase alphabet and numbers,
 * followed by a new line
 * description: 'Hexadecimal'
 * Return: always 0
 */

int main(void)
{
int n;
int m;

for (n = 48; n <= 57; n++)
{
putchar(n);
}
for (m = 97; m <= 102; m++)
{
putchar(m);
}
putchar('\n');
return (0);
}
