#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_all - Print anything.
 * @format: List of types of arguments.
 * @...: The values to format and print.
 *
 */
void print_all(const char * const format, ...)
{
    va_list args;
    char *str;
    unsigned int i = 0;

    va_start(args, format);
    while (format && format[i])
    {
        switch (format[i])
        {
        case 'c':
            printf("%c", va_arg(args, int));
            break;
        case 'i':
            printf("%d", va_arg(args, int));
            break;
        case 'f':
            printf("%f", va_arg(args, double));
            break;
        case 's':
            str = va_arg(args, char*);
            if (!str)
                str = "(nil)";
            printf("%s", str);
            break;
        default:
            i++;
            continue;
        }
        if (format[i + 1])
            printf(", ");
        i++;
    }
    printf("\n");
    va_end(args);
}
