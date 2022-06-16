#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

/**
 * struct op_s - opcode, argument and stack
 * @input: stream represent input instruction
 * @opcode: the opcode
 * @arg: argument
 * @head: linked list representing stack
 */
typedef struct op_s
{
	FILE *input;
	char *opcode;
	char *arg;
	stack_t *head;
} op_t;

extern op_t op;

/* main.c */
void exit_error(char *message);
void read_file(void);
void exec_code(char *line, unsigned int line_number);
void get_op(char *line);

/* get_op_func.c */
void (*get_op_func(void))(stack_t **, unsigned int);

/* op_functions.c */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
int is_valid_int(char *str);
void free_list(stack_t *head);
void free_op(void);

/* strings.c */
char *_strcpy(char *dest, const char *src);
unsigned int _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strtok(char *str, const char *delim);

#endif /* MONTY_H */
