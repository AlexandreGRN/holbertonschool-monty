#include "monty.h"

int push(stack_t **top, int i)
{
	stack_t *node = (malloc(sizeof(stack_t)));

	if (!node)
		return (NULL);

	node->prev = *head;
	node->n = n;
	node->next = *head;

	*head = node;                                                                                                                                                                                                                                             
