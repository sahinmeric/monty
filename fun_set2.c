#include "monty.h"
/**
 * _sub - subtracts the top element of the stack from the second.
 * @stack: Stack list
 * @line_ctr: Line number
 */
void _sub(stack_t **stack, unsigned int line_ctr)
{
	stack_t *current = *stack;
	int sub = 0;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_ctr);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	sub = current->next->n - current->n;
	current->next->n = sub;
	_pop(stack, line_ctr);
}
