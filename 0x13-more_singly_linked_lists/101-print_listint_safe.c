#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow_ptr, *fast_ptr;
	size_t count = 0;

	if (!head)
		return (0);

	slow_ptr = head;
	fast_ptr = head->next;

	while (fast_ptr && fast_ptr->next)
	{
		if (slow_ptr == fast_ptr)
		{
			printf("-> [%p] %d\n", (void *)slow_ptr, slow_ptr->n);
			return (count);
		}
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		printf("[%p] %d\n", (void *)slow_ptr, slow_ptr->n);
		count++;
	}
	return (count);
}

