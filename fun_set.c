#include "monty.h"

int value;
/**
 * new_Node - create new node
 * @n: is a value
 * Return: new node
 */
stack_t *new_Node(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}

/**
 * _push - push item
 * @stack: stack
 * @line_number: value
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = new_Node(value);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * _pall - print elements stack
 * @stack: stack
 * @n: value
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int n)
{
	stack_t *current = NULL;
	(void)n;

	if (!*stack)
		return;
	current = *stack;

	while (current != NULL)
	{
		fprintf(stderr, "%d\n", current->n);
		current = current->next;
	}
}
/**
 * _pint - prints the value at the top of the stack.
 * @stack: Stack list
 * @line_ctr: line ctr
 */
void _pint(stack_t **stack, unsigned int line_ctr)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_ctr);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}
