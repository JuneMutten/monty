#include "monty.h"

/**
 * check_argc - Checks the number of command-line arguments
 * @argc: Argument counter
 */

void check_argc(int argc)
{
	if (argc != 2)
	{
		printf("ERROR: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * check_file_stream - Checks if the file stream is valid
 * @fp: File stream
 * @file_name: Name of the file
 */

void check_file_stream(FILE *fp, char *file_name)
{
	if (fp == NULL)
	{
		printf("ERROR: Could not open file");
		exit(EXIT_FAILURE);
	}
}
