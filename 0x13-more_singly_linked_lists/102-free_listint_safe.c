#include "lists.h"
#include <stdlib.h>

/**
* free_listint_safe - Free a listint_t list
* @h: Double pointer to the head of the list
*
* Return: Size of the list that was free'd
*/
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp, *current;
	size_t nodes = 0;

	if (!h || !*h)
		return (0);

	current = *h;

	while (current)
	{
		nodes++;
		temp = current;
		current = current->next;
		free(temp);

		if (temp <= current)
		{
			*h = NULL;
			return (nodes);
		}
	}

	*h = NULL;
	return (nodes);
}

