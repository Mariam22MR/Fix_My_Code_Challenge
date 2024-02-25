#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - add node at the end of list
 * @head: address of pointer to first element of list
 * @n: number to store in new element
 *
 * Return: pointer to new element
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *i;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		new->prev = NULL;
		return (new);
	}
	i = *head;
	while (i->next != NULL)
	{
		i = i->next;
	}
	i->next = new;
	new->prev = i;
	return (new);
}
