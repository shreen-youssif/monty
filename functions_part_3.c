#include "monty.h"

/**
 * mul - Multiply the second top element of the stack with the top element.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void mul(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        handle_error("L%d: can't mul, stack too short", line_number);
    }

    (*stack)->next->n *= (*stack)->n;
    pop(stack, line_number);
}
/**
 * mod - Compute the rest of the division of the second top element by the top element.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void mod(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        handle_error("L%d: can't mod, stack too short", line_number);
    }

    if ((*stack)->n == 0)
    {
        handle_error("L%d: division by zero", line_number);
    }

    (*stack)->next->n %= (*stack)->n;
    pop(stack, line_number);
}
