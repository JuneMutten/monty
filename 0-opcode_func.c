#include "monty.h"

/**
 * push_stk - Adds a value to the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number where opcode is found
 */
void push_stk(stack_t **stack, unsigned int line_number)
{
	int result;

	if (value[1] == 0)
		result = add_to_stack(stack, value[0]);
	else
		result = add_to_queue(stack, value[0]);

	if (result < 0)
	{
		printf("l%d: Error: push integer\n", line_number);
		value[2] = 1;
		return;
	}
}

/**
 * pall_stk - prints all values of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number where the opcode is located
 */
void pall_stk(stack_t **stack, unsigned int line_number  __attribute__((unused)))
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (tmp == NULL)
	{
		fprintf(stderr, "ERROR: empty stack\n");
		return;

		printf("Stack values:\n");

		while (tmp != NULL)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
}

/**
 * pint_stk - Prints the top elmennt
 * @stack: Pointer to head of the stack
 * @line_number: Line number where the opcode is located
 */
void pint_stk(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;

	if (head == NULL)
	{
		printf("L%d: ERROR: nothing to print stack is empty\n", line_number);
		value[2] = 1;
		return;
	}

	printf("%d\n", head->n);
}

/**
 * pop_stk - Removes the top element of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number where the opcode is located
 */

void pop_stk(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		printf("L%d: ERROR: stack is empty nothing to pop\n", line_number);
		value[2] = 1;
		return;
	}

	tmp = (*stack);

	if (tmp->next == NULL)
	{
		free(tmp);
		(*stack) = NULL;
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}

/**
 * swap_stk - Swaps the top  two elements
 * @stack: Pointer to the head to the stack
 * @line_number: Line number where opcode is located
 */

void swap_stk(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2;
	int tmp_value;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: ERROR: stack is too short to swap\n", line_number);
		value[2] = 1;
		return;
	}

	tmp = (*stack);
	tmp2 = tmp->next;
	tmp_value = tmp->n;
	tmp->n = tmp2->n;
	tmp2->n = tmp_value;
}


