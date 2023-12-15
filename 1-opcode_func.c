#include "monty.h"

/**
 * add_stk - Adds the top two elements of the stack
 * @stack: Head to the stack
 * @line_number: Line number where the opcode is located
 */

void add_stk(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	stack_t *tmp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: ERROR: stack is too short to add\n", line_number);
		value[2] = 1;
		return;
	}

	tmp = (*stack);
	tmp2 = tmp->next;
	tmp->n = tmp->next->n + tmp->n;
	tmp->next = tmp2->next;

	if (tmp2->next != NULL)
		tmp2->next->prev = tmp;

	else
		tmp->next = NULL;

	free(tmp2);
}

/**
 * nop_stk - Does nothing
 * @stack: Pointer to head to the stack
 * @line_number: Line number where opcode is located
 */
void nop_stk(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}


