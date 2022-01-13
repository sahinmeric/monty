#include "monty.h"
glob_t global = {NULL, NULL};
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS if no errors are passed
 * EXIT_FAIlURE otherwise
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
	read_op(argv[1]);
	}
return (EXIT_SUCCESS);
}

/**
 * read_op - Read the opcode
 * @argv: argument vector
 * Return: Nothing
 */
void read_op(char *argv)
{
	size_t bufsize = 0;
	char *line = NULL, *tkn = NULL; /*line => opcode*/
	stack_t *stack = NULL;
	int result = 0, line_count = 0;
	/*read the file*/
	global.fptr = fopen(argv, "r"); /*fopen returns file pointer or null */
	if (global.fptr)
	{
	while (getline(&global.line, &bufsize, global.fptr) != -1)
	{
		line_count++;
		line = strtok(global.line, " \n\t\r");
	if (line == NULL)
	{
		free(line);
		continue;
	}
	else if (*line == '#') /*if the line is comment*/
		continue;
	tkn = strtok(NULL, " \n\t\r");
	result = get_op(&stack, line, tkn, line_count);
	if (result == 1)
		push_error(global.fptr, global.line, stack, line_count);
	else if (result == 2)
		push_error(global.fptr, global.line, stack, line_count);
	}
	free(global.line);
	free_dlistint(stack);
	fclose(global.fptr);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
/**
 * get_op - handle the opcode
 * @stack: is a stack or queue
 * @line: line
 * @tkn: token
 * @line_count: line count
 * Return: 0, 1 or 2
 */
int get_op(stack_t **stack, char *line, char *tkn, int line_count)
{
	int i = 0, res;

	instruction_t op[] = {
	{"push", _push},
	{"pall", _pall},
	{"pint", _pint},
	{"pop", _pop},
	{"swap", _swap},
	{NULL, NULL}
	};

	while (op[i].opcode)
	{
	res = strcmp(line, op[i].opcode);
	if (res == 0)
	{
		if (!strcmp(line, "push"))
		{
			if (_isdigit(tkn) == 1)
			{
				value = atoi(tkn);
			}
			else
			return (1);
		}
	op[i].f(stack, (unsigned int)line_count);
	break;
	}
	i++;
}
	if (!op[i].opcode)
		return (2);
	return (0);
}
