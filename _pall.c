#include "monty.h"
/**
 * _pall - Prints all values in the stack
 * @stack: A pointer to the top of the stack
 * @line_number: Line number of the opcode (unused)
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
		(void)line_number; /*Unused variable*/
	}
}
