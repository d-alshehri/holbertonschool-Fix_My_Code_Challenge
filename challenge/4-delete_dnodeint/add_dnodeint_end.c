#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a node at the end of a list
 * @head: Pointer to pointer to the first element of the list
 * @n: Number to store in the new element
 *
 * Return: Pointer to the new element, or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new = malloc(sizeof(dlistint_t));
    dlistint_t *l;

    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
    {
        new->prev = NULL;
        *head = new;
        return (new);
    }

    l = *head;
    while (l->next != NULL)
        l = l->next;

    l->next = new;
    new->prev = l;

    return (new);
}
