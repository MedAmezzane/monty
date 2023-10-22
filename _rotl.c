#include "monty.h"
/**
 * _rotl - Rotates the stack to the top.
 * @stack: Pointer to the stack's top.
 * @line_number: Line number (unused).
 */
void _rotl(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack, *new_top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	new_top = (*stack)->next;
	new_top->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = new_top;
}
