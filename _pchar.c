#include "monty.h"

/**
 * _pchar - Prints the character at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the file.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int character;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	character = (*stack)->n;
	if (character < 0 || character > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", character);
}
