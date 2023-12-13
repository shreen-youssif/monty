#include "monty.h"
/**
 * swap - Swap the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;
    if (!stack || !*stack || !(*stack)->next)
    {
        handle_error("L%d: can't swap, stack too short", line_number);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
