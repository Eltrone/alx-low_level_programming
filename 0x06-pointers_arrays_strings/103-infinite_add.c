#include "main.h"

/**
* infinite_add - Adds two numbers
* @n1: The first number
* @n2: The second number
* @r: The buffer to store the result
* @size_r: The buffer size
*
* Return: A pointer to the result or 0 if it cannot be stored
*/
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, l, m, n, carry = 0, sum;

	for (i = 0; n1[i] != '\0'; i++)
		;
	for (j = 0; n2[j] != '\0'; j++)
		;

	if (size_r <= i + 2 || size_r <= j + 2)
		return (0);

	k = 0;
	i--;
	j--;
	while (i >= 0 || j >= 0 || carry > 0)
	{
		m = (i >= 0) ? n1[i] - '0' : 0;
		n = (j >= 0) ? n2[j] - '0' : 0;

		sum = m + n + carry;
		if (sum > 9)
		{
			r[k] = (sum % 10) + '0';
			carry = 1;
		}
		else
		{
			r[k] = sum + '0';
			carry = 0;
		}
		k++;
		i--;
		j--;
	}

	r[k] = '\0';

	// Inversion de la chaîne
	for (l = 0, m = k - 1; l < k / 2; l++, m--)
	{
		char temp = r[l];
		r[l] = r[m];
		r[m] = temp;
	}

	return (r);
}
