#include "monty.h"

/**
 * push_error - handle push error
 * @fd:file desciptor
 * @line:opc buffer
 * @stack:stack or queue
 * @line_ctr:line counter
 */
void push_error(FILE *fd, char *line, stack_t *stack, int line_ctr)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_ctr);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}

/**
 * ins_error - Error handler
 * @fd: file descriptor
 * @line: opc buffer
 * @stack: stack or queue
 * @line_ctr: line counter
 * @item: int number
 */
void ins_error(FILE *fd, char *line, stack_t *stack, char *line_ctr, int item)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", item, line_ctr);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
