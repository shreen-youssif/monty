#define _POSIX_C_SOURCE 200809L
#include "monty.h"
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ptrdiff_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    char *opcode;
    char *arg;

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

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        /* Skip lines that start with '#' (comments) or are empty */
        if (line[0] == '#' || line[0] == '\n')
        {
            continue;
        }

        /* Tokenize the line to get opcode and argument */
        arg = strtok(line, " \t\n");
        opcode = arg;

        if (opcode && strcmp(opcode, "push") == 0)
        {
            arg = strtok(NULL, " \t\n");
            if (!arg || !atoi(arg))
            {
                handle_error("L%d: usage: push integer", line_number);
            }

            push(&stack, atoi(arg), line_number);
        }
        else if (opcode && strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else if (opcode && strcmp(opcode, "pint") == 0)
        {
            pint(&stack, line_number);
        }
        else if (opcode && strcmp(opcode, "pop") == 0)
        {
            pop(&stack, line_number);
        }
        else if (opcode && strcmp(opcode, "swap") == 0)
        {
            swap(&stack, line_number);
        }
        else if (opcode && strcmp(opcode, "add") == 0)
        {
            add(&stack, line_number);
        }
        else if (opcode && strcmp(opcode, "nop") == 0)
        {
            nop(&stack, line_number);
        }
        else if (opcode && strcmp(opcode, "sub") == 0)
        {
            sub(&stack, line_number);
        }
        else if (opcode && strcmp(opcode, "div") == 0)
        {
            div_op(&stack, line_number);
        }
        else if (opcode && strcmp(opcode, "mul") == 0)
        {
            mul(&stack, line_number);
        }
        else if (opcode && strcmp(opcode, "mod") == 0)
        {
            mod(&stack, line_number);
        }
        else if (opcode && strcmp(opcode, "pchar") == 0)
        {
            pchar(&stack, line_number);
        }
        else if (opcode && strcmp(opcode, "pstr") == 0)
        {
            pstr(&stack, line_number);
        }
        else
        {
            handle_error("L%d: unknown instruction %s", line_number, opcode);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);

    return (EXIT_SUCCESS);
}

