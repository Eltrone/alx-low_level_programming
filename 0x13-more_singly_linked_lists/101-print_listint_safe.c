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
	const listint_t *slow, *fast;
	size_t nodes = 0;

	if (head == NULL)
		exit(98);

	slow = head;
	fast = head;

	while (slow && fast && fast->next)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		nodes++;
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			nodes++;
			break;
		}
	}

	return (nodes);
}
