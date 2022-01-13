#include "monty.h"

/**
 * _pop - removes the top element of the stack.
 * @stack: Stack list
 * @line_ctr: Number of the line
 */
void _pop(stack_t **stack, unsigned int line_ctr)
{
	stack_t *current = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_ctr);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
}
