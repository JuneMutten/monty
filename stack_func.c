#include "monty.h"

/**
 * add_to_stack - Adds new node to the beggining of the stack
 * @head: Pointer to the head of the stack
 * @n: Integer to be added
 * Return: 1 if success and -1 otherwise
 */
int add_to_stack(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	new_node->n = n;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		new_node->next = NULL;
		 (*head) = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
	return (1);
}

/**
 * free_stack - Frees the stack
 * @head: head of the stack
 */

void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
