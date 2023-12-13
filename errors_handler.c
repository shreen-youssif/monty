#include "monty.h"
/**
 * handle_error - Print a formatted error message to stderr.
 * @message: Format string for the error message.
 * @...: Variable arguments corresponding to placeholders.
*/

void handle_error(const char *message, ...)
{
    va_list args;
    va_start(args, message);
    vfprintf(stderr, message, args);
    va_end(args);
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
}
/**
 * is_valid_integer - Check if a string is a valid integer.
 * @str: String to check.
 * Return: 1 if valid integer, 0 otherwise.
 */
int is_valid_integer(const char *str)
{
    if (!str || *str == '\0')
        return 0;

    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}
/**
 * rotr - Rotate the stack to the bottom.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *current, *new_bottom;

    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    current = *stack;

    while (current->next)
        current = current->next;

    new_bottom = current;
    new_bottom->next = *stack;
    new_bottom->prev->next = NULL;

    (*stack)->prev = new_bottom;
    current->next = *stack;
    (*stack)->prev = current;

    *stack = new_bottom;
}
