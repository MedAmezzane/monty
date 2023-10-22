#include "monty.h"
/**
 * free_stack - Frees a stack_t linked list.
 * @stack: Pointer to the top of the stack.
 *
 * This function iterates through the stack and frees all the nodes,
 * including their contents.
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
