#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 * @head: Pointer to pointer to the first element of the list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    /* Traverse to the node at index */
    for (i = 0; i < index; i++)
    {
        if (current->next == NULL)
            return (-1); /* index out of bounds */
        current = current->next;
    }

    /* If it's the first node, update head */
    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next;

    /* Update next node's prev pointer if it exists */
    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    return (1);
}
