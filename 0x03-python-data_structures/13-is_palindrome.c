#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *temp = *head;
    int buffer[2048];
    int i = 0, j;

    if (!head || !(*head) || !((*head)->next))
        return (1);

    while (temp)
    {
        buffer[i++] = temp->n;
        temp = temp->next;
    }

    for (j = 0; j < i / 2; j++)
    {
        if (buffer[j] != buffer[i - 1 - j])
            return (0);
    }

    return (1);
}
