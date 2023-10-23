#include "lists.h"
#include <stdio.h>

/**
* print_listint_safe - print a listint_t list safely
* @head: pointer to the head of the list
*
* Return: the number of nodes in the list
*/
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0;
	int loop_detected = 0;

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		head = head->next;

		if (!loop_detected)
		{
			if (slow == fast && head)
			{
				loop_detected = 1;
				fast = head->next;
			}
			else
			{
				slow = slow->next;
				if (fast && fast->next)
					fast = fast->next->next;
			}
		}
	}

	if (loop_detected)
		printf("-> [%p] %d\n", (void *)slow, slow->n);

	return count;
}

