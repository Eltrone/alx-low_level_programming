#include <stdio.h>

/**
 * main - program that prints the alphabet in lowercase,
 * followed by a new line
 * description: 'alphabet in lower case'
 * Return: always 0
 */

int main(void)
{
int n = 97;

while (n < 123)
{
putchar(n);
n++;
}
putchar('\n');
return (0);
}
