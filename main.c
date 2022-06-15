#include "monty.h"
#include <stdio.h>

/**
 * main - starts the Monty interpreter program
 * @argc: number of commandline arguments
 * @argv: array of commandline arguments
 *
 * Return: EXIT_SUCCESS on success. EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *input;

	/* check usage */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open given file */
	input = fopen(argv[1], "r");
	if (input == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_file(input);

	return (EXIT_SUCCESS);
}

/**
 * exit_error - writes a given message to stderr and exits with EXIT_FAILURE status
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
 * @input: file stream
 */
void read_file(FILE *input)
{
	char *buffer = NULL;
	size_t bufferSize = 0;

	while (getline(&buffer, &bufferSize, input) != -1)
	{
		printf("%s", buffer);
	}

	if (buffer)
		free(buffer);
}
