#include "lists.h"

/**
* free_listint_safe - frees a listint_t list.
* @h: double pointer to the start of the list.
* Return: the size of the list that was free’d.
*/
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow = *h, *fast = *h, *temp;
	size_t count = 0;

	if (!h || !*h)
		return (0);

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			do {
				temp = slow;
				slow = slow->next;
				free(temp);
				count++;
			} while (slow != fast);
			*h = NULL;
			return (count);
		}
	}

	while (*h)
	{
		temp = *h;
		*h = (*h)->next;
		free(temp);
		count++;
	}
	*h = NULL;
	return (count);
}

