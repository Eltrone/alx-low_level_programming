#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to be printed
 *
 * Description: Prints the key/value pairs in the order they appear in the
 *              hash table array. Format: {'key': 'value', ...}
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	int flag = 0;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			if (flag == 1)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			flag = 1;
			node = node->next;
		}
	}
	printf("}\n");
}
