#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table to add or update the key/value to
 * @key: The key, cannot be an empty string
 * @value: The value associated with the key, must be duplicated
 *
 * Description: In case of collision, adds the new node at the beginning
 *              of the list.
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *temp_node;
	unsigned long int index;

	if (!ht || !key || strlen(key) == 0 || !value)
		return (0);

	/* Get the index for this key */
	index = key_index((const unsigned char *)key, ht->size);

	/* Check for collision and handle if necessary */
	temp_node = ht->array[index];
	while (temp_node)
	{
		if (strcmp(temp_node->key, key) == 0)
		{
			free(temp_node->value);
			temp_node->value = strdup(value);
			return (1);
		}
		temp_node = temp_node->next;
	}

	/* Create new node */
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (!new_node->key || !new_node->value)
	{
		free(new_node);
		return (0);
	}

	/* Insert the new node */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
