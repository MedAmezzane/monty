#include "monty.h"
/**
 * _pstr - Prints the string starting at the top of the stack, followed by
 * a new line.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number of the opcode in the Monty file.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number; /* Unused parameter */

	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
