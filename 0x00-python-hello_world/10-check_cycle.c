#include "lists.h"

/**
 * check_cycle - Checks for a cycle in a singly linked list
 * @list: Pointer to the start of the linked list
 * 
 * Description: Traverses the list using two pointers, one moving one node at a
 * time (current) and the other moving two nodes at a time (check).
 * If these two pointers meet, a cycle is detected in the list.
 *
 * Return: 0 if no cycle is present, 1 if a cycle is detected
 */
int check_cycle(listint_t *list)
{
	listint_t *current, *check;

	if (list == NULL || list->next == NULL)
		return (0);
	current = list;
	check = current->next;

	while (current != NULL && check->next != NULL && check->next->next != NULL)
	{
		if (current == check)
			return (1);
		current = current->next;
		check = check->next->next;
	}
	return (0);
}

