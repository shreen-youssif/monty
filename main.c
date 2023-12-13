#include "monty.h"
/**
 * main - Entry point for the Monty program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise.
*/
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_file(file, &stack);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
