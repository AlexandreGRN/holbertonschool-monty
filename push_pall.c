#include "monty.h"

void push(stack_t **top, unsigned int line_number)
{
	stack_t *node = (malloc(sizeof(stack_t)));

	if (!node)
	{
		dprintf(STDERR_FILENO, "L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	(void) line_number;

	node->prev = *top;
	node->n = n;
	node->next = NULL;
	*top = node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *toprint = *stack;

	(void) line_number;
	while (toprint->prev)
	{
		printf("%d\n", toprint->n);
		toprint = toprint->prev;
	}
}
