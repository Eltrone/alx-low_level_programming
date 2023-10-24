#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Print a listint_t linked list
 * @head: Pointer to the head of the list
 *
 * Return: Number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t nodes = 0;

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		nodes++;

		if (current->next >= current)
		{
			printf("-> [%p] %d\n", (void *)current->next, current->next->n);
			nodes++;
			break;
		}

		current = current->next;
	}

	return (nodes);
}

