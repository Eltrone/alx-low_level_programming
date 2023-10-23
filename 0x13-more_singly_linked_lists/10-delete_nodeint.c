#include "lists.h"

/**
* delete_nodeint_at_index - Deletes the node at index of a listint_t list
* @head: Pointer to the head of the list
* @index: Index of the node to delete, starting at 0
*
* Return: 1 if succeeded, -1 if failed
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *temp, *next_node;
    unsigned int i;

    if (!*head)
        return (-1);

    temp = *head;

    if (index == 0)
    {
        *head = temp->next;
        free(temp);
        return (1);
    }

    for (i = 0; i < index - 1; i++)
    {
        if (!temp)
            return (-1);
        temp = temp->next;
    }

    if (!temp || !temp->next)
        return (-1);

    next

