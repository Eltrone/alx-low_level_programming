#include "hash_tables.h"

/**
 * hash_djb2 - Implements the djb2 hash function
 * @str: The string to hash
 *
 * Description: This function implements the well-known djb2 hashing algorithm,
 *              which is a simple yet effective hash function.
 *
 * Return: The calculated hash as an unsigned long int
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	/* Iterate over each character in the string */
	while ((c = *str++))
	{
		/* Hash formula: hash * 33 + current character */
		hash = ((hash << 5) + hash) + c;
	}

	return (hash);
}
