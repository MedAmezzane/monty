#include "monty.h"
/**
 * _pop - Removes the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the opcode.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/* Set new_top to point to the next node in the stack */
	new_top = (*stack)->next;

	/* Free the memory allocated for the current top node of the stack */
	free(*stack);
	
	/* Update the head pointer to point to the new top node */
	*stack = new_top;
	
	if (*stack != NULL)
	/* Update the prev pointer of the new top node to NULL */
		(*stack)->prev = NULL;
}
