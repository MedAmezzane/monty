#include "monty.h"
/**
 * _swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)

	tmp->next->prev = *stack;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}
