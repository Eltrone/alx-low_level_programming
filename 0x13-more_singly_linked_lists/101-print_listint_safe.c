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
	size_t count = 0;
	const listint_t *hare, *tortoise;
	int loop_detected = 0;

	if (head == NULL)
		exit(98);

	tortoise = hare = head;

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			loop_detected = 1;
			break;
		}
	}

	if (!loop_detected)
	{
		while (head)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			count++;
			head = head->next;
		}
		return (count);
	}

	tortoise = head;
	while (tortoise != hare)
	{
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		count++;
		tortoise = tortoise->next;
		hare = hare->next;
	}

	printf("[%p] %d\n", (void *)tortoise, tortoise->n);
	count++;

	tortoise = tortoise->next;
	while (tortoise != hare)
	{
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		count++;
		tortoise = tortoise->next;
	}

	printf("-> [%p] %d\n", (void *)tortoise, tortoise->n);

	return (count);
}

