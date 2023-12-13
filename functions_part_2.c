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
/**
 * add - Add the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        handle_error("L%d: can't add, stack too short", line_number);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}
/**
 * nop - Does nothing.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
/**
 * sub - Subtract the top element of the stack from the second top element.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        handle_error("L%d: can't sub, stack too short", line_number);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}
