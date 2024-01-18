#include "monty.h"

/**
 * f_div - Divides the top two elements of the stack.
 * @head: Stack head
 * @counter: Line number
 *
 * Return: No return value
 */
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *current = *head;
    int stack_size = 0, result;

    while (current)
    {
        current = current->next;
        stack_size++;
    }

    if (stack_size < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        handle_error_exit(head); /* Pass head as an argument */
    }

    current = *head;
    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        handle_error_exit(head); /* Pass head as an argument */
    }

    result = current->next->n / current->n;
    current->next->n = result;
    *head = current->next;
    free(current);
}

/**
 * handle_error_exit - Handles error, closes files, frees memory, and exits.
 * @head: Stack head
 */
void handle_error_exit(stack_t **head)
{
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
}
