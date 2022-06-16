#include "monty.h"

/**
 * get_op_func - selects the correct function using a given string
 *
 * Return: a pointer to the function that corresponds to op.opcode.
 * Otherwise NULL
 */
void (*get_op_func(void))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{NULL, NULL}
	};

	if (op.opcode == NULL)
		return (NULL);

	while (ops[i].opcode)
	{
		if (strcmp(op.opcode, ops[i].opcode) == 0)
			return (ops[i].f);

		i++;
	}

	return (NULL);
}
