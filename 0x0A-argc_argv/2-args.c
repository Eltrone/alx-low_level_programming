#include "main.h"

/**
* main - Print all arguments
* @argc: Argument count
* @argv: Argument vector
* Return: 0 (Success)
*/
int main(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
