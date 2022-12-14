#include "monty.h"

/**
 * pint_f - print the value at the top of the stack
 * @stack: list
 * @line_number: line count
 */
void pint_f(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_f - removes the top of the slack
 * @stack: list
 * @line_number: line count
 */
void pop_f(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		(*stack) = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	//else
	//	free(*stack);

}

/**
 * add_f - adds the value of the 2 lasts things
 * @stack: list
 * @line_number: line count
 */
void add_f(stack_t **stack, unsigned int line_number)
{
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	m = (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n + m;
}

/**
 * swap_f - swap the 2 last stack
 * @stack: list
 * @line_number: line count
 */
void swap_f(stack_t **stack, unsigned int line_number)
{
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	m = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = m;
}
/**
 * nop_f - do nothing
 * @stack: list
 * @line_number: line count
 */
void nop_f(stack_t **stack, unsigned int line_number)
{
	(void) *stack;
	(void) line_number;
}
