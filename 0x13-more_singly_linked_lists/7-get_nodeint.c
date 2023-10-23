#include "lists.h"

/**
* get_nodeint_at_index - returns the nth node of a listint_t list.
* @head: pointer to the head node.
* @index: index of the node to return.
*
* Return: nth node or NULL if node does not exist.
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}
	return (NULL);
}

