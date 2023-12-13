#include "monty.h"

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
