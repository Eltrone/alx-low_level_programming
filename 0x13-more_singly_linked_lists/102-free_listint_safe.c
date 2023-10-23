#include "lists.h"

/**
* free_listint_safe - frees a listint_t list.
* @h: double pointer to the head of the list
*
* Return: the size of the list that was free’d
*/
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current;
	listint_t *next_node;

	if (!h || !*h)
		return (0);

	current = *h;
	while (current)
	{
		count++;
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*h = NULL;
	return (count);
}

