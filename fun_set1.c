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
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_ctr);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
}
/**
 * _swap - swaps the top two elements of the stack.
 * @stack: Stack
 * @line_ctr: Number of the line
 */
void _swap(stack_t **stack, unsigned int line_ctr)
{
	stack_t *current = *stack;
	int temp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_ctr);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
/**
 * _add - function add two integer
 * @stack: Stack list
 * @line_ctr: Number of the line
 */
void _add(stack_t **stack, unsigned int line_ctr)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_ctr);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	_pop(stack, line_ctr);
}
