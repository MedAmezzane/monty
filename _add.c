#include "monty.h"
/**
 * _add - Adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode
 */
void _add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        free(glob.line);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    _pop(stack, line_number);
}
