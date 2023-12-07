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
	unsigned int i = 0;
	dlistint_t *copy_head = *h;
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (*h == NULL)
	{
		*h = new;
		return (new);
	}

	if (idx == 0)
	{
		new->next = copy_head;
		copy_head->prev = new;
		*h = new;
		return (new);
	}

	while (copy_head)
	{
		if (i == idx - 1)
		{
			if (copy_head->next)
				copy_head->next->prev = new;
			new->next = copy_head->next;
			copy_head->next = new;
			new->prev = copy_head;
			return (new);
		}
		copy_head = copy_head->next;
		i++;
	}

	free(new);
	return (NULL);
}
