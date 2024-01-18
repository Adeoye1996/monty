#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom.
 * @head: Pointer to the stack head.
 * @counter: Line number (unused).
 * Return: No return value.
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *current = *head;
    stack_t *new_head = NULL;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    while (current->next)
    {
        current = current->next;
    }

    new_head = current;
    current->prev->next = NULL;
    current->prev = NULL;
    new_head->next = *head;
    (*head)->prev = new_head;
    *head = new_head;
}
