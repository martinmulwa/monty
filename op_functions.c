#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @stack: pointer to the pointer to the first element in stack
 * @line_number: line number of the instruction
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *new;

	if (is_valid_int(op.arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}
	num = atoi(op.arg);

	/* add num to beginning of stack */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failedr\n");
		free_op();
		exit(EXIT_FAILURE);
	}

	new->n = num;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}


/**
 * op_pall - prints all the values on the stack, from the top
 * @stack: pointer to the pointer to the first element in stack
 * @line_number: line number of the instruction
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *trav = *stack;

	while (trav)
	{
		printf("%d\n", trav->n);
		trav = trav->next;
	}

	(void)line_number;
}


/**
 * op_pint - prints the value at the top of the stack
 * @stack: pointer to the pointer to the first element in stack
 * @line_number: line number of the instruction
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}


/**
 * is_valid_int - checks if a given string is a valid integer
 * @str: string
 *
 * Return: 1 if str is a valid integer. 0 otherwise
 */
int is_valid_int(char *str)
{
	if (str == NULL)
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}
