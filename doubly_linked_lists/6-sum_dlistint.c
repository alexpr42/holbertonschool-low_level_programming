#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n) of a dlistint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The sum of all the data (n) of the list.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	/* Traverse the list and accumulate the sum */
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
