#include <stdio.h>

/**
 * main - program that prints all possible combinations
 * followed by a new line
 * description: 'print combination'
 * Return: always 0
 */

int main(void)
{
int n;

for (n = 48; n <= 57; n++)
{
putchar(n);
if (n == 57)
{
continue;
}
putchar(',');
putchar(' ');
}
putchar('\n');
return (0);
}
