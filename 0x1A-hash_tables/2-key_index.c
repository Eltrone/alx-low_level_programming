#include "hash_tables.h"

/**
 * key_index - Gives the index of a key in a hash table array
 * @key: The key to hash
 * @size: The size of the array of the hash table
 *
 * Description: This function uses the hash_djb2 function to calculate
 *              the hash value of the key and then returns the index at
 *              which the key/value pair should be stored in the array
 *              of the hash table.
 *
 * Return: The index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_val;

	/* Calculate hash value using hash_djb2 */
	hash_val = hash_djb2(key);

	/* Modulo operation to fit hash value into table size */
	return (hash_val % size);
}
