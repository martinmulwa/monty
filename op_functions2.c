#include "monty.h"

/**
 * op_add - adds the top two elements of the stack
 * @stack: pointer to the pointer to the first element in stack
 * @line_number: line number of the instruction
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	op_pop(stack, line_number);
}


/**
 * op_nop - does nothing
 * @stack: pointer to the pointer to the first element in stack
 * @line_number: line number of the instruction
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
