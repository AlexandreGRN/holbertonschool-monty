#include "monty.h"

/**
 * sub_f - subs the value of the 2 lasts things
 * @stack: list
 * @line_number: line count
 */
void sub_f(stack_t **stack, unsigned int line_number)
{
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	m = (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n - m;
}

/**
 * div_f - divs the value of the 2 lasts things
 * @stack: list
 * @line_number: line count
 */
void div_f(stack_t **stack, unsigned int line_number)
{
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	m = (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n / m;
}

/**
 * mul_f - muls the value of the 2 lasts things
 * @stack: list
 * @line_number: line count
 */
void mul_f(stack_t **stack, unsigned int line_number)
{
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	m = (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n * m;
}

