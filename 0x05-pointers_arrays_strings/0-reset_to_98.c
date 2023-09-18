#include "main.h"
#include <stdio.h>

/**
 * reset_to_98 - Updates the value of an integer variable through a pointer.
 * @n: Pointer to the integer variable to be updated.
 *
 * Description: This function takes a pointer to an integer as its parameter
 * and updates the value it points to to 98.
 * Return: None.
 */
void reset_to_98(int *n)
{
    *n = 98;
}
