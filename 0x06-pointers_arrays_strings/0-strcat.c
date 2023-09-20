#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string to append to dest
 *
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
    char *ptr = dest;

    /* Find the end of the dest string */
    while (*ptr)
        ptr++;

    /* Copy the src string to the end of dest */
    while (*src)
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    /* Add the null terminator */
    *ptr = '\0';

    return dest;
}
