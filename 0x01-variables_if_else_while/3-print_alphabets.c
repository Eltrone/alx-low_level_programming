#include <stdio.h>

/**
 * main - program that prints the alphabet in lowercase and uppercase,
 * followed by a new line
 * description: 'alphabet in lower case'
 * Return: always 0
 */

int main(void)
{
int n = 97;
int m = 65;

while (n < 123)
{
putchar(n);
n++;
}
while (m < 91)
{
putchar(m);
m++;
}

putchar('\n');
return (0);
}
