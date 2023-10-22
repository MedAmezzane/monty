#include "monty.h"

/**
 * executeFile - Reads and executes opcodes from a file.
 * @stack: Pointer to the top of the stack.
 */
void executeFile(stack_t **stack)
{
	char *currentLine = NULL;
	size_t lineLength = 0;
	ssize_t bytesRead;
	unsigned int line_number = 0;

	while ((bytesRead = getline(&glob.line, &lineLength, glob.file)) != -1)
	{
		line_number++;
		currentLine = strtok(glob.line, " \t\r\n\a");
		glob.arg = strtok(NULL, " \n\t");
		if (currentLine == NULL || *currentLine == '#')
			continue;
		executeOpcode(currentLine, stack, line_number);
	}
}

/**
 * executeOpcode - Executes a single opcode.
 * @opcode: Opcode to execute.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void executeOpcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}

