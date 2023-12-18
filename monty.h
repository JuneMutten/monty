#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int value[];

/* errors.c */
void check_argc(int argc);
void check_file_stream(FILE *fp, char *filename);

/* 0-helper.c */
void check_data_structure(char *opcode);
int check_empty(const char *s);
int check_comment(char **buffer);
int check_push(char *token_line[], int line_no);
int check_number(char *str);

/* 1-helper.c */
int tokenize_line(char *s, char *tokens[]);
void check_fail(char *line, FILE *fp, stack_t *head);
void check_opcode(void (*opcode)(), int line_no, char *cmd);
void clear_strings(char *buffer[]);

/* stack_func.c */
int add_to_stack(stack_t **head, int n);
void free_stack(stack_t *head);

/* queue_func.c */
int add_to_queue(stack_t **head, int n);

/* 0-opcode_func_c */
void push_stk(stack_t **stack, unsigned int line_number);
void pall_stk(stack_t **stack, unsigned int line_number);
void pint_stk(stack_t **stack, unsigned int line_number);
void pop_stk(stack_t **stack, unsigned int line_number);
void swap_stk(stack_t **stack, unsigned int line_number);

/* 1-opcode_func.c */
void add_stk(stack_t **stack, unsigned int line_number);
void nop_stk(stack_t **stack, unsigned int line_number);

/* get_opcode_func.c */
void (*get_opcode_func(char *s))(stack_t **stack, unsigned int line_number);

/* stack_func.c */
int add_to_stack(stack_t **head, int n);

#endif
