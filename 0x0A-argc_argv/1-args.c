#include "main.h"

/**
* main - Print the number of arguments
* @argc: Argument count
* @argv: Argument vector
* Return: 0 (Success)
*/
int main(int argc, char **argv)
{
	(void) argv;
	printf("%d\n", argc - 1);
	return (0);
}
