#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node, starting from 0.
 *
 * Return: Pointer to the nth node, or NULL if the node does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	/* Traverse the list until reaching the desired index */
	while (head != NULL && i < index)
	{
		head = head->next;
		i++;
	}

	/* If head is NULL or index exceeds the number of nodes, return NULL */
	if (head == (NULL)
			return (NULL);

	return (head);
}
