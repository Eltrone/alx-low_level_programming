#include <stdio.h>

/**
 * main - program that prints the alphabet in lowercase,
 * except q and e ,followed by a new line
 * description: 'alphabet in lower case'
 * Return: always 0
 */

int main(void)
{
int n = 97;

while (n < 123)
{
if (n != 101 && n != 113)
{
putchar(n);
n++;
}
else
{
n++;
}
}
putchar('\n');
return (0);
}
