#include "monty.h"
/**
 * _sub - Subtracts the top element of the stack from the second top element.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number in the file.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int subtraction_result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	subtraction_result = temp->next->n - temp->n;
	temp->next->n = subtraction_result;
	*stack = temp->next;
	free(temp);
}
