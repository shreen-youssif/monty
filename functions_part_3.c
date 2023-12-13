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
 * mod - Compute the rest of the division of the second top
 *	element by the top element.
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
/**
 * pchar - Print the character at the top of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		handle_error("L%d: can't pchar, stack empty", line_number);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		handle_error("L%d: can't pchar, value out of range", line_number);
	}

	putchar((*stack)->n);
	putchar('\n');
}
/**
 * pstr - Print the string starting at the top of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current && current->n != 0 && (current->n >= 0 && current->n <= 127))
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
/**
 * rotl - Rotate the stack to the top.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new_top;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	current = *stack;
	while (current->next)
		current = current->next;

	new_top = (*stack)->next;
	new_top->prev = NULL;
	(*stack)->next = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = new_top;
}
