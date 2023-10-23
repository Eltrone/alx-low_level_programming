#include "lists.h"

/**
 * pop_listint - deletes the head node and returns its data
 * @head: double pointer to the head of the list
 *
 * Return: data of the head node
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *tmp;

	if (*head == NULL)
		return (0);

	tmp = *head;
	n = tmp->n;
	*head = (*head)->next;
	free(tmp);

	return (n);
}

