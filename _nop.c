#include "monty.h"

/**
 * _nop - a no-operation function that does nothing
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
