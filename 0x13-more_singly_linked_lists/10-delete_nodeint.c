#include "lists.h"

/**
* delete_nodeint_at_index - Deletes the node at index of a listint_t list.
* @head: Double pointer to the head of the list.
* @index: The index of the node to be deleted.
*
* Return: 1 if succeeded, -1 if failed.
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *previous;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	for (i = 0; current && i < index; i++)
	{
		previous = current;
		current = current->next;
	}

	if (!current)
		return (-1);

	previous->next = current->next;
	free(current);
	return (1);
}

