#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_numbers - Print numbers.
 * @separator: Separator between numbers.
 * @n: Number of integers.
 * @...: Integers.
 *
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list args;
    unsigned int i;
    int num;

    va_start(args, n);
    for (i = 0; i < n; i++)
    {
        num = va_arg(args, int);
        printf("%d", num);

        if (separator != NULL && i < n - 1)
        {
            printf("%s", separator);
        }
    }
    printf("\n");
    va_end(args);
}
