#define _POSIX_C_SOURCE 200809L
#include "monty.h"
/**
 * read_file - Reads lines from a file and processes Monty bytecode.
 * @file: File to read.
 * @stack: Pointer to the stack.
*/
void read_file(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	ptrdiff_t read;
	unsigned int line_number = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		if (line[0] == '#' || line[0] == '\n')
		{
			continue;
		}

		tokenize_line(line, line_number, stack);
	}

	free(line);
}

/**
 * tokenize_line - Tokenizes a line to get opcode and argument.
 * @line: Line to tokenize.
 * @line_number: Line number for error reporting.
 * @stack: Pointer to the stack.
*/
void tokenize_line(char *line, unsigned int line_number, stack_t **stack)
{
	char *arg = strtok(line, " \t\n");
	char *opcode = arg;

	if (!opcode)
	{
		return;
	}

	execute_opcode(opcode, strtok(NULL, " \t\n"), line_number, stack);
}

/**
 * execute_opcode - Executes the corresponding operation based on the opcode.
 * @opcode: Opcode to execute.
 * @arg: Argument associated with the opcode.
 * @line_number: Line number for error reporting.
 * @stack: Pointer to the stack.
*/
void execute_opcode(char *opcode, char *arg,
			unsigned int line_number, stack_t **stack)
{
	if (strcmp(opcode, "push") == 0)
	{
		if (!arg || !is_valid_integer(arg))
		{
			handle_error("L%d: usage: push integer", line_number);
		}
		push(stack, atoi(arg), line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);
	else if (strcmp(opcode, "div") == 0)
		div_op(stack, line_number);
	else if (strcmp(opcode, "mul") == 0)
		mul(stack, line_number);
	else if (strcmp(opcode, "mod") == 0)
		mod(stack, line_number);
	else if (strcmp(opcode, "pchar") == 0)
		pchar(stack, line_number);
	else if (strcmp(opcode, "pstr") == 0)
		pstr(stack, line_number);
	else if (strcmp(opcode, "rotl") == 0)
		rotl(stack, line_number);
	else if (strcmp(opcode, "rotr") == 0)
		rotr(stack, line_number);
	else
	{
		handle_error("L%d: unknown instruction %s", line_number, opcode);
	}
}
