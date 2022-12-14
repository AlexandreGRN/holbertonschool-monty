#include "monty.h"

int numMonty;

void push_f(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *newNode = NULL;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}
	newNode->prev = NULL;
	newNode->next = *stack;
	newNode->n = numMonty;
	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}

void pall_f(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *toprint = *stack;

	while (toprint != NULL)
	{
		printf("%d\n", toprint->n);
		if (toprint->next != NULL)
		{
			toprint = toprint->next;
		}
		else
			break;
	}
}
