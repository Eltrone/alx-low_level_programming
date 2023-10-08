#include "main.h"

/**
* multiply - multiplies two strings of digits
* @s1: first string
* @s2: second string
* @result: array to store the result
* @len: length of the result array
*/
void multiply(char *s1, char *s2, int *result, int len)
{
	int len1 = _strlen(s1);
	int len2 = _strlen(s2);
	int i, carry, digit1, digit2;

	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = s1[len1] - '0';
		carry = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			digit2 = s2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
}
