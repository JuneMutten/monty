#include "monty.h"

/**
 * check_data_structure - Checks whether opcode is that of a stack or a queue
 * @opcode: Opcode being checked
 * 0 if its stack and 1 if its queue
 */

void check_data_structure(char *opcode)
{
	if (strcmp(opcode, "stack") == 0)
		value[1] = 0;

	else if (strcmp(opcode, "queue") == 0)
		value[1] = 1;
}

/**
 * check_empty - Checks if a string is empty
 * @s: String to be checked
 * Return: 1 if empty, 0 otherwise
 */
int check_empty(const char *s)
{
	while (*s != '\0')
	{
		if (!isspace((unsigned char)*s))
			return (0);
		s++;
	}

	return (1);
}

/**
 * check_comment - Checks if line is comment
 * @buffer: Pointer to the string
 * Return: 1 if comment, 0 if not
 */

int check_comment(char **buffer)
{
	if (*buffer[0] == '#')
	{
		*buffer[0] = '\0';
		return (1);
	}

	return (0);
}

/**
 * check_push - Checks if the opcode is string and sets value
 * @token_line: Line of the opcode
 * @line_no: Line number
 * Return: 1 if success, 0 otherwise
 */
int check_push(char *token_line[], int line_no)
{
	if (strcmp(token_line[0], "push") == 0)
	{
		if (token_line[1][0] != '\0' && check_number(token_line[1]))
			value[0] = atoi(token_line[1]);
		else
		{
			printf("l%d: ERROR: Non integer pushed\n", line_no);
			value[2] = 1;
			return (0);
		}

		return (1);
	}

	return (0);
}

/**
 * check_number - Checks if a string is a number
 * @str: String to be checked
 * Return: 1 if true or 0 otherwise
 */

int check_number(char *str)
{
	int i;

	if (str && *str == '-')
		str++;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}


