#include "monty.h"
void push(stack_t **stack, int value, unsigned int line_number)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        handle_error("Error: malloc failed", line_number);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	
	(void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void free_stack(stack_t *stack)
{
    stack_t *current = stack;
    stack_t *next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
/**
 * pint - Print the value at the top of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        handle_error("L%d: can't pint, stack empty", line_number);
    }

    printf("%d\n", (*stack)->n);
}
