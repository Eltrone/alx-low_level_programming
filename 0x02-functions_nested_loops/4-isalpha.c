#include "main.h"

/**
 * _isalpha - a function that checks for alphabetic character.
 * @c: The character to be checked
 * Return: returns 1 if 'c' is letter, lowercase or uppercase
 *         otherwise always 0 (Success)
 */
int _isalpha(int c)
{
if ((c >= 65 && c <= 97)  ||  (c >= 97 && c <= 122))
{
return (1);
}
return (0);
}
