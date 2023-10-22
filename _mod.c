#include "monty.h"

/**
 * _mod - Computes the modulus of the second top element of the stack
 *		with the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int divisor, dividend;

	/* Check if the stack is empty or has insufficient elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;
	dividend = (*stack)->next->n;

	/* Check for division by zero */
	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = dividend % divisor;
	_pop(stack, line_number);
}
