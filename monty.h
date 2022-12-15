#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern int numMonty;
void push_f(stack_t **stack, unsigned int line_number);
void pall_f(stack_t **stack, unsigned int line_number);
void pint_f(stack_t **stack, unsigned int line_number);
void pop_f(stack_t **stack, unsigned int line_number);
void swap_f(stack_t **stack, unsigned int line_number);
void add_f(stack_t **stack, unsigned int line_number);
void nop_f(stack_t **stack, unsigned int line_number);
void push_f(stack_t **stack, unsigned int line_number);
void pall_f(stack_t **stack, unsigned int line_number);
void sub_f(stack_t **stack, unsigned int line_number);
void div_f(stack_t **stack, unsigned int line_number);
void mul_f(stack_t **stack, unsigned int line_number);

#endif
