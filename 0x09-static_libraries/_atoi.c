#include "main.h"

/**
* _atoi - Converts a string to an integer.
* @s: The string to be converted.
*
* Return: The integer value of the converted string.
*/
int _atoi(char *s)
{
	int i = 0, sign = 1, num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			num = (num * 10) + (s[i] - '0');
		}
		else if (num > 0)
		{
			break;
		}
		i++;
	}
	return (num * sign);
}
