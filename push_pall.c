#include "monty.h"

int numMonty;

void push_f(stack_t **top, unsigned int line_number)
{
	stack_t *node = (malloc(sizeof(stack_t)));

	if (!node)
	{
		fprintf(stderr, "L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	(void) line_number;

	node->prev = NULL;
	node->n = numMonty;

	if (top != NULL)
	{
		node->next = *top;
		(*top)->prev = node;
	}
	else
		node->next = NULL;
	*top = node;
}

void pall_f(stack_t **stack, unsigned int line_number)
{
	stack_t *toprint = *stack;

	(void) line_number;
	while (toprint != NULL)
	{
		printf("%d\n", toprint->n);
		toprint = toprint->prev;
	}
}
