#include "monty.h"
/**
 * _pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the opcode.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
