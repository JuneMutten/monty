#include "monty.h"
#include <stddef.h>

/**
 * main - Entry point of the function
 * @argc: Argument counter
 * @argv: Argument vector
 * Return: 0 on success
 */
int value[3] = {0, 0, 0};

int main(int argc, char *argv[])
{
	/* int value[3] = {0, 0, 0}; */
	char *path, *line, *token_line[2];
	FILE *fp;
	void (*fptr)(stack_t **stack, unsigned int line_number);
	stack_t *head;
	size_t len, line_no, token_status;
	ssize_t read;

	head = NULL;
	line = NULL;
	check_argc(argc);
	path = argv[1];

	fp = fopen(path, "r");
	check_file_stream(fp, path);

	for (line_no = 1; (read = getline(&line, &len, fp)) != -1; line_no++)
	{
		if (check_empty(line))
			continue;
		token_status = tokenize_line(line, token_line);

		if (token_status == 0)
			continue;
		check_push(token_line, line_no);
		check_fail(line, fp, head);
		check_data_structure(token_line[0]);
		fptr = get_opcode_func(token_line[0]);
		check_opcode(fptr, line_no, token_line[0]);
		check_fail(line, fp, head);
		(*fptr)(&head, line_no);
		check_fail(line, fp, head);
		clear_strings(token_line);
	}
	free(line);
	fclose(fp);
	free_stack(head);
	return (0);
}


