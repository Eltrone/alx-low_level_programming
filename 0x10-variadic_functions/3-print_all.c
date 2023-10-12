#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
* print_char - Print a character
* @list: The va_list
*/
void print_char(va_list list)
{
	printf("%c", va_arg(list, int));
}

/**
* print_int - Print an integer
* @list: The va_list
*/
void print_int(va_list list)
{
	printf("%d", va_arg(list, int));
}

/**
* print_float - Print a float
* @list: The va_list
*/
void print_float(va_list list)
{
	printf("%f", va_arg(list, double));
}

/**
* print_string - Print a string
* @list: The va_list
*/
void print_string(va_list list)
{
	char *s = va_arg(list, char *);

	if (s == NULL)
		s = "(nil)";
	printf("%s", s);
}

/**
* print_all - Print anything
* @format: A list of types of arguments passed to the function
* @...: The values to format and print
*/
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	int j;
	char *separator = "";

	typedef void (*print_func_t)(va_list);
	print_func_t funcs[] = {print_char, print_int, print_float, print_string};
	char types[] = {'c', 'i', 'f', 's'};

	va_start(args, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == types[j])
			{
				printf("%s", separator);
				funcs[j](args);
				separator = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
