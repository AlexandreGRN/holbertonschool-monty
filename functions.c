#include "monty.h"

/**
 * pint_f - print the value at the top of the stack
 * @stack: list
 * @line_number: line count
 */
void pint_f(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	printf("%d\n", (*stack)->n);
}

/**
 * pop_f - removes the top of the slack
 * @stack: list
 * @line_number: line count
 */
void pop_f(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * add_f - adds the value of the 2 lasts things
 * @stack: list
 * @line_number: line count
 */
void add_f(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int m;

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
void swap_f(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int m;

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
	(void) stack;
	(void) line_number;
}
