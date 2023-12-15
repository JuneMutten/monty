#include "monty.h"

/**
 * get_opcode_func - Selects the function that matches the command
 * @s: Opcode passed to the program
 * Return: Pointer to the function given the opcode or NULL if not found
 */

void (*get_opcode_func(char *s))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t stk[] = {
		{"push", push_stk},
		{"pall", pall_stk},
		{"pint", pint_stk},
		{"pop", pop_stk},
		{"swap", swap_stk},
		{"add", add_stk},
		{"nop", nop_stk},
		{NULL, NULL}
	};

	i = 0;

	while (i < 7)
	{
		if (strcmp(s, (stk[i]).opcode) == 0)
		{
			return (*(stk[i]).f);
		}

		i++;
													}

	return (NULL);
}
