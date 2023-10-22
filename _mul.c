#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the file
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	/* Check if the stack is empty or has insufficient elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	result = temp->next->n * temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
