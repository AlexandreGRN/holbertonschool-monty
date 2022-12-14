#include "monty.h"

int numMonty;
/**
 * numberval - transfo num input into integer
 * @num: number
 */
void numberval(char *num)
{
	if (num)
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

				numberval(tok);
				inst[i].f(stack, lineNumber); /* call _f function if */
			}
			j++;
		}
		/* if it does not reconized the command*/
		if (j == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, linebuf);
			exit(EXIT_FAILURE);
		}
	}
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
	unsigned int lineNumber = 0;
	stack_t *stack = NULL;

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
}
