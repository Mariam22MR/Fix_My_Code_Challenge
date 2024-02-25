#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - delete node at specific index from list
 * @head: pointer to first element of list
 * @index: index of node to delete
 *
 * Return: 1 on success, -1 on failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if ((head == NULL) || (*head == NULL))
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}
	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}
	if (0 == index)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
		(*head)->prev->next = (*head)->next;
		tmp = (*head)->prev;
		free(*head);
		if (tmp->next)
			tmp->next->prev = tmp;
		*head = saved_head;
	}
	return (1);
}
