#include "main.h"

/**
 * times_table - a function that prints
 * the 9 times table, starting with 0
 */
void times_table(void)
{
    int num, mult, prod;

    for (num = 0; num <= 9; num++)
    {
        _putchar(48);
        for (mult = 1; mult <= 9; mult++)
        {
            prod = num * mult;
            if (prod <= 9)
            else
                _putchar((prod / 10) + 48);
            _putchar((prod % 10) + 48);
        }
    }
}
