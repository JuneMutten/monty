#include "monty.h"

/**
 * add_to_queue - Adds new node to the end of the queue
 * @head: Pointer to the head of the queue
 * @n: Integer to be added to the queue
 * Return: 1 if success, 0 otherwise
 */
int add_to_queue(stack_t **head, int n)
{
	stack_t *new_node, *tmp;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: malloc faied\n");
		return (-1);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
	}
	return (1);
}

