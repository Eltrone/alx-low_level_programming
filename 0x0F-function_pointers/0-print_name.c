#include "function_pointers.h"
#include <stdio.h>

/**
* print_name - Prints a name
* @name: The name to print
* @f: The printing function to use
*/
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
