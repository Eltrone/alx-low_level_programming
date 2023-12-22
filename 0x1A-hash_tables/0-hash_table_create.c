#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - Creates a new hash table
 * @size: The size of the array of the hash table
 *
 * Return: A pointer to the new hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	unsigned long int i;

	/* Allocate memory for the hash table structure */
	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);

	/* Initialize the table */
	hash_table->size = size;
	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	/* Initialize node pointers to NULL */
	for (i = 0; i < size; i++)
		hash_table->array[i] = NULL;

	return (hash_table);
}
