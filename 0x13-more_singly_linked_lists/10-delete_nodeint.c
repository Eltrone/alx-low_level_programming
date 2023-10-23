#include <stdio.h>
#include <stdlib.h>

/**
* struct Node - node for singly linked list
* @data: data in node
* @next: pointer to the next node
*/
struct Node
{
	int data;
	struct Node *next;
};

/**
* delete_node_at_index - deletes the node at index of a listint_t linked list
* @head: pointer to pointer to head of the list
* @index: index of the node to delete, starts at 0
* Return: 1 if success, -1 if failure
*/
int delete_node_at_index(struct Node **head, unsigned int index)
{
	struct Node *tmp = *head, *prev;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = tmp->next;
		free(tmp);
		return (1);
	}

	while (tmp != NULL)
	{
		if (i == index)
		{
			prev->next = tmp->next;
			free(tmp);
			return (1);
		}
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

/**
* main - main function to test delete_node_at_index
* Return: 0 if success
*/
int main(void)
{
	struct Node *head = malloc(sizeof(struct Node));
	struct Node *second = malloc(sizeof(struct Node));
	struct Node *third = malloc(sizeof(struct Node));

	if (head == NULL || second == NULL || third == NULL)
		return (1);

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	if (delete_node_at_index(&head, 1) == 1)
		printf("Node deleted!\n");
	else
		printf("Node could not be deleted.\n");

	free(head);
	free(second);
	free(third);

	return (0);
}

