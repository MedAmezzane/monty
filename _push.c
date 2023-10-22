#include "monty.h"
/**
 * _push - Pushes an integer onto the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Current line number in the Monty file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int number;

	if (glob.arg == NULL || !is_valid_number(glob.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}

	number = atoi(glob.arg);
	if (add_node(stack, number) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_valid_number - Checks if a string represents a valid integer
 * @str: The string to check
 *
 * Return: 1 if the string represents a valid integer, 0 otherwise
 */
int is_valid_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}

