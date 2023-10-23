#include "lists.h"

/**
* print_listint_safe - Prints a listint_t linked list safely.
* @head: Pointer to the head of the list.
*
* Return: Number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t count = 0;

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		if (current <= current->next)
		{
			current = current->next;
			printf("-> [%p] %d\n", (void *)current, current->n);
			break;
		}
		current = current->next;
	}
	return (count);
}

