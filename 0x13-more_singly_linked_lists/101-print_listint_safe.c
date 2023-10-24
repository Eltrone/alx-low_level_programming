#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
* print_listint_safe - print a listint_t list safely
* @head: head of the list
*
* Return: the number of nodes in the list
*/

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *hare, *tortoise;
	size_t count = 0;

	if (head == NULL)
		exit(98);

	hare = head;
	tortoise = head;

	while (hare != NULL && hare->next != NULL)
	{
		printf("[%p] %d\n", (void *)hare, hare->n);
		hare = hare->next->next;
		tortoise = tortoise->next;
		count++;
		if (hare == tortoise)
		{
			printf("[%p] %d\n", (void *)hare, hare->n);
			return (count);
		}
	}

	hare = head;
	while (hare != NULL)
	{
		printf("[%p] %d\n", (void *)hare, hare->n);
		hare = hare->next;
		count++;
	}

	return (count);
}

