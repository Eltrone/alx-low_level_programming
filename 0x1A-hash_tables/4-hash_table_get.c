#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key in a hash table
 * @ht: The hash table to look into
 * @key: The key to find
 *
 * Description: Returns the value associated with the key, or NULL if the key
 *              couldn't be found in the hash table.
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (!ht || !key || strlen(key) == 0)
		return (NULL);

	/* Get the index for this key */
	index = key_index((const unsigned char *)key, ht->size);

	/* Search for the key in the linked list at that index */
	node = ht->array[index];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}
