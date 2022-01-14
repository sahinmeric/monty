#include "monty.h"
/**
 * int_error - handle push error
 * @fd:file desciptor
 * @line:opc buffer
 * @stack:stack or queue
 * @line_ctr:line counter
 */
void int_error(FILE *fd, char *line, stack_t *stack, int line_ctr)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_ctr);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
/**
 * push_error - handle push error
 * @fd:file desciptor
 * @line:opc buffer
 * @stack:stack or queue
 * @line_ctr:line counter
 */
void push_error(FILE *fd, char *line, stack_t *stack, int line_ctr)
{
	fprintf(stderr, "L%u: usage: unknown integer\n", line_ctr);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}

/**
 * ins_error - Error handler
 * @fd: is a file descriptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @count: is a line command
 * @item: number
 */
void ins_error(FILE *fd, char *line, stack_t *stack, char *count, int item)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", item, count);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
