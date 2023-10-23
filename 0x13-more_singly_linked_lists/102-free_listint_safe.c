#include "lists.h"
#include <stdlib.h>

/**
* free_listint_safe - free a listint_t list safely
* @h: double pointer to the head of the list
*
* Return: the size of the list that was freed
*/
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;
	size_t count = 0;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		count++;
		temp = *h;
		*h = (*h)->next;
		free(temp);

		if (temp <= *h)
			break;
	}

	*h = NULL;
	return (count);
}

