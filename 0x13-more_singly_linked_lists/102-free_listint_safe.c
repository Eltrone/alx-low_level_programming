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
	listint_t *temp, *address_array[1024];
	size_t count = 0, i;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		for (i = 0; i < count; i++)
		{
			if (address_array[i] == *h)
			{
				*h = NULL;
				return (count);
			}
		}

		address_array[count++] = *h;
		temp = *h;
		*h = (*h)->next;
		free(temp);
	}

	*h = NULL;
	return (count);
}

