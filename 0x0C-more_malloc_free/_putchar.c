#include <unistd.h>

/**
* _putchar - writes the string to stdout
* @str: The string to print
*/
void _putchar(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
