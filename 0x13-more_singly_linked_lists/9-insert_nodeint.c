#include "lists.h"
#include <stdlib.h>

/**
* insert_nodeint_at_index - inserts a new node at a given index.
* @head: double pointer to the head node.
* @idx: index where the new node should be added.
* @n: data for the new node.
*
* Return: address of the new node, or NULL if it failed.
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *tmp;
	unsigned int i = 0;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	tmp = *head;
	while (tmp != NULL)
	{
		if (i == idx - 1)
		{
			new_node->next = tmp->next;
			tmp->next = new_node;
			return (new_node);
		}
		tmp = tmp->next;
		i++;
	}
	free(new_node);
	return (NULL);
}

