#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int p;

	if (head == NULL || *head == NULL)
		return (-1);

	tmp = *head;
	p = 0;

	/* Traverse to the node at index */
	while (tmp && p < index)
	{
		tmp = tmp->next;
		p++;
	}

	/* If index is out of range */
	if (tmp == NULL)
		return (-1);

	/* Case: deleting the head node */
	if (tmp->prev == NULL)
	{
		*head = tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		/* Relink previous node */
		tmp->prev->next = tmp->next;

		/* Relink next node */
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
	}

	free(tmp);
	return (1);
}
