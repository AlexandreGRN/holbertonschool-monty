#include "monty.h"

int numMonty;
/**
 * numberval - transfo num input into integer
 * @num: number
 */
void numberval(char *num, int line)
{
	int i = 0;

	if (!num)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	for (i = 0 ; num[i] ; i++)
	{
		if (!(num[0] == '-' || (num[i] >= 48 && num[i] <= 57)))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
	}

	numMonty = atoi(num);
}

/**
 * tokenize_call - tokenize a line and call a function if possible
 * @linebuf: line we want to check
 * @lineNumber: line number
 */
void tokenize_call(char *linebuf, unsigned int lineNumber, stack_t **stack)
{
	char *tok = "1";
	char delim[] = " \t\n";
	int i = 0;
	int j = 0;

	/* creating instruction list of all possible actions */
	instruction_t inst[] = {
		{"push", push_f},
		{"pall", pall_f},
		{"pint", pint_f},
		{"pop", pop_f},
		{"swap", swap_f},
		{"add", add_f},
		{"nop", nop_f},
		{NULL, NULL},
	};

	/* tokenize + call if needed */
	while (tok)
	{
		tok = strtok(linebuf, delim);
		linebuf = NULL;
		/* if opcode (push for exemple) exists in the line, call a function */
		for (; inst[i].opcode != NULL ; i++)
		{
			if (tok && strcmp(inst[i].opcode, tok) == 0) /* if function call */
			{
				tok = strtok(linebuf, delim); /* recup the argument */
			/*	if (tok == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
					exit(EXIT_FAILURE);
				} */
				if (i == 0)
					numberval(tok, lineNumber);
				inst[i].f(stack, lineNumber); /* call _f function if */
				return;
			}
			j++;
		}
		/* if it does not reconized the command*/
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, tok);
		exit(EXIT_FAILURE);
	}
	free(tok);
}

/**
 * main - get the input from the monty file and send info to sub function
 * @argc : arg counter
 * @argv: arg vector
 * Return: 1
 */

int main(__attribute__((unused))int argc, char **argv)
{
	FILE *fd;
	char linebuf[1024];
	unsigned int lineNumber = 1;
	stack_t *stack = NULL;
	stack_t *tmp;

	/* if does not have the executable and the monty file */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* get the monty file info */
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(linebuf, 1024, fd) != NULL)
	{
		/* call a function if match */
		tokenize_call(linebuf, lineNumber, &stack);
		lineNumber++;
	}
	fclose(fd);
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}

	free(stack);
}
