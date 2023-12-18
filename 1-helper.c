#include "monty.h"
#include <string.h>

/**
 * tokenize_line - Tokenizes the commands
 * @s: Command to be tokenized
 * @tokens: Buffer to hold the tokens
 * Return: 1 if success 0, otherwise
 */
char *strtok_r(char *str, const char *delim, char **saveptr);

int tokenize_line(char *s, char *tokens[])
{
	int i, status;
	char *buffer, *hold;

	buffer = strtok_r(s, " \t\n", &hold);
	status = check_comment(&buffer);

	if (status == 1)
		return (0);

	for (i = 0; buffer && i < 2; i++)
	{
		tokens[i] = buffer;

		buffer = strtok_r(NULL, " \t\n", &hold);
	}

	return (1);
}

/**
 * check_fail - Check if a fail has been raised. If so, free memory and exit
 * @line: buffer to free
 * @fp: file stream to close
 * @head: head of the stack
 * Return: return 1 if exit triggered, else 0 for false
 */

void check_fail(char *line, FILE *fp, stack_t *head)
{
	if (value[2] == 1)
	{
		free(line);
		fclose(fp);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_opcode - Checks if opcode function pointer is NULL
 * @opcode: Opcode function pointer
 * @line_no: Line number
 * @cmd: Command given
 */

void check_opcode(void (*opcode)(), int line_no, char *cmd)
{
	if (opcode == NULL)
	{
		printf("L%d: ERROR: command not found %s\n", line_no, cmd);
		value[2] = 1;
		return;
	}
}

/**
 * clear_strings - Reset strings in an array
 * @buffer: Stores the strings
 */

void clear_strings(char *buffer[])
{
	int i;

	for (i = 0; buffer[i]; i++)
		buffer[i][0] = '\0';
}

