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
void tokenize_call(char *linebuf, unsigned int lineNumber)
{
	char *tok;
	char delim[] = " \t\n";
	int i = 0, num = 0;
	stack_t **stack = NULL;

	/* creating instruction list of all possible actions */
	instruction_t inst[] = {
		{"push", push_f},
		{"pall", pall_f},
		{NULL, NULL},
	};

	/* tokenize + call if needed */
	while (tok)
	{
		tok = strtok(linebuf, delim);
		linebuf = NULL;
		/* if opcode (push for exemple) exists in the line, call a function */
		while (inst[i].opcode != NULL)
		{
			if (strcmp(inst[i].opcode, tok) == 0) /* if function call */
			{
				tok = strtok(linebuf, delim); /* recup the argument */
				numberval(tok);
				inst[i].f(stack, lineNumber); /* call _f function if */
			}
			i++;
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

	/* get the monty file info */
	fd = fopen(argv[1], "r");
	while (fgets(linebuf, 1024, fd) != NULL)
	{
		/* call a function if match */
		tokenize_call(linebuf, lineNumber);
		lineNumber++;
	}
	fclose(fd);
}
