#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - Test doubly linked list functions
 *
 * Return: Always 0
 */
int main(void)
{
    dlistint_t *head = NULL;
    int i;

    /* Add nodes to the end of the list */
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);

    printf("Initial list:\n");
    print_dlistint(head);
    printf("-----------------\n");

    /* Delete a specific index */
    if (delete_dnodeint_at_index(&head, 5) == -1)
        printf("Failed to delete index 5\n");
    print_dlistint(head);
    printf("-----------------\n");

    /* Delete all remaining nodes from head */
    printf("Deleting all remaining nodes:\n");
    while (head)
    {
        if (delete_dnodeint_at_index(&head, 0) == -1)
            printf("Failed to delete index 0\n");
        print_dlistint(head);
        printf("-----------------\n");
    }

    /* Free the list and set head to NULL */
    free_dlistint(head);
    head = NULL;

    return (0);
}
