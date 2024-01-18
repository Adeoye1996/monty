#include "monty.h"

/**
 * f_queue - Sets the queue mode (FIFO).
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return value.
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 1;
}

/**
 * addqueue - Adds a new node to the tail of the stack (queue).
 * @head: Pointer to the head of the stack.
 * @n: New value.
 * Return: No return value.
 */
void addqueue(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    aux = *head;
    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = NULL;

    if (!aux)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        while (aux->next)
            aux = aux->next;

        aux->next = new_node;
        new_node->prev = aux;
    }
}
