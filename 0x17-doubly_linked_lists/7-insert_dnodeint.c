#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index where the new node should be added
 * @n: data for the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *current;
    unsigned int i = 0;

    if (h == NULL)
        return (NULL);

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (idx == 0)
    {
        new_node->next = *h;
        if (*h != NULL)
            (*h)->prev = new_node;
        *h = new_node;
        return (new_node);
    }

    current = *h;
    while (current != NULL && i < idx)
    {
        if (i == idx - 1)
        {
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next != NULL)
                current->next->prev = new_node;
            current->next = new_node;
            return (new_node);
        }
        current = current->next;
        i++;
    }

    free(new_node);
    return (NULL);
}

