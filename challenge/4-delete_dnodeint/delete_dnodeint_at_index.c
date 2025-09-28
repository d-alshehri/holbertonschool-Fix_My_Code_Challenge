#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: Pointer to pointer to the first element of the list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    unsigned int p = 0;
    dlistint_t *tmp;

    if (head == NULL || *head == NULL)
        return (-1);

    tmp = *head;

    /* Traverse to the node at index */
    while (tmp && p < index)
    {
        tmp = tmp->next;
        p++;
    }

    if (tmp == NULL)
        return (-1);

    /* Deleting the head node */
    if (tmp->prev == NULL)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        /* Re-link previous and next nodes in one line each */
        (*head)->prev->next = (*head)->next;
        if ((*head)->next != NULL)
            (*head)->next->prev = (*head)->prev;
    }

    free(tmp);
    return (1);
}
