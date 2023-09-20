#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s1[] = "Hello";
    char s2[] = "World!";

    printf("%d\n", _strcmp(s1, s2));
    printf("%d\n", _strcmp(s2, s1));
    printf("%d\n", _strcmp(s1, s1));
    return (0);
}

3-strcmp.c
#include "main.h"

/**
 * _strcmp - a function that compares two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if true, 0 if false
 */

int _strcmp(char *s1, char *s2)
{
	int line = 0;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			line = ((int)*s1 - 48) - ((int)*s2 - 48);
			break;
		}
		s1++;
		s2++;
	}
	return (line);
}
