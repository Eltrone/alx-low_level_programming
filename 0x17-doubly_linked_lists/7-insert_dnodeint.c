#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index where the new node should be added
 * @n: data for the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int count = 0;

	if (idx == 0)  // Utiliser add_dnodeint pour l'insertion au début
		return (add_dnodeint(h, n));

	for (temp = *h; temp && count < idx; temp = temp->next, count++)
		;

	if (!temp && count == idx)  // Utiliser add_dnodeint_end pour l'insertion à la fin
		return (add_dnodeint_end(h, n));
	else if (temp)
	{
		new_node = malloc(sizeof(dlistint_t));
		if (!new_node)
			return (NULL);

		new_node->n = n;
		new_node->prev = temp->prev;
		new_node->next = temp;
		if (temp->prev)
			temp->prev->next = new_node;
		temp->prev = new_node;

		return (new_node);
	}

	return (NULL);
}
