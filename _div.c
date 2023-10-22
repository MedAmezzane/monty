#include "monty.h"
/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number in the file.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int quotient;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	quotient = temp->next->n / temp->n;
	temp->next->n = quotient;
	*stack = temp->next;
	free(temp);
}
