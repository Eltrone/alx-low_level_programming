#include <stdio.h>

/**
 * main - program that prints the Numbers,
 * followed by a new line
 * description: 'print numbers of base'
 * Return: always 0
 */

int main(void)
{
int n;

for (n = 0; n <= 9; n++)
{
putchar(n + 48);
}
putchar('\n');
return (0);
}
