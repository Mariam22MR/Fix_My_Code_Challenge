#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - free list
 * @head: pointer to first element of list
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *node;

	while (head)
	{
		node = head;
		head = head->next;
		free(node);
	}
}
