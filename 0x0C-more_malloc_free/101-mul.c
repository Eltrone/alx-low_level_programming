#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* is_digit - vérifie si une chaîne est un nombre
* @s: la chaîne à vérifier
* Return: 1 si vrai, 0 sinon
*/
int is_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
* main - Multiplie deux nombres
* @argc: Nombre d'arguments
* @argv: Tableau d'arguments
* Return: 0 en cas de succès, 98 en cas d'erreur
*/
int main(int argc, char *argv[])
{
	int i, j, carry, len1, len2;
	int *result;
	char *num1, *num2;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];
	len1 = strlen(num1);
	len2 = strlen(num2);

	result = calloc(len1 + len2, sizeof(int));
	if (!result)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			int mul = (num1[i] - '0') * (num2[j] - '0') + carry;
			carry = (mul + result[i + j + 1]) / 10;
			result[i + j + 1] = (mul + result[i + j + 1]) % 10;
		}
		result[i] += carry;
	}

	for (i = 0; i < len1 + len2; i++)
	{
		if (i == 0 && result[i] == 0)
			continue;
		printf("%d", result[i]);
	}
	printf("\n");

	free(result);
	return (0);
}
