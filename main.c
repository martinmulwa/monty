#include "monty.h"
#include <stdio.h>

op_t op = {NULL, NULL, NULL, NULL};

/**
 * main - starts the Monty interpreter program
 * @argc: number of commandline arguments
 * @argv: array of commandline arguments
 *
 * Return: EXIT_SUCCESS on success. EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	/* check usage */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open given file */
	op.input = fopen(argv[1], "r");
	if (op.input == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_file();

	free_op();
	return (EXIT_SUCCESS);
}

/**
 * exit_error - writes a given message to stderr and exits
 * @message: message to write to stderr
 */
void exit_error(char *message)
{
	write(STDERR_FILENO, message, strlen(message));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

/**
 * read_file - reads from a given file stream line by line
 */
void read_file(void)
{
	char line[1024];
	size_t line_len = 1023;
	unsigned int line_number = 0;

	while (fgets(line, line_len, op.input))
	{
		line_number++;
		exec_code(line, line_number);
	}

}

/**
 * exec_code - checks if a given string is a valid instruction and executes it
 * @line: string
 * @line_number: line number of current instruction
 */
void exec_code(char *line, unsigned int line_number)
{
	void (*f)(stack_t **, unsigned int);
	char *message;

	get_op(line);

	if (op.opcode == NULL || op.opcode[0] == '#')
		return;

	f = get_op_func();
	if (f == NULL)
	{
		message = "L%u: unknown instruction %s\n";
		fprintf(stderr, message, line_number, op.opcode);
		free_op();
		exit(EXIT_FAILURE);
	}

	f(&(op.head), line_number);
}

/**
 * get_op - gets the correct operation from a given string and updates op
 * @line: string
 */
void get_op(char *line)
{
	char *str = line;

	while (*str)
	{
		if (*str < ' ')
			*str = ' ';

		str++;
	}

	if (op.opcode)
		free(op.opcode);

	if (op.arg)
		free(op.arg);

	op.opcode = _strdup(_strtok(line, " "));
	op.arg = _strdup(_strtok(NULL, " "));
}
