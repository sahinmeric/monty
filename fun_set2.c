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
/**
 * _div - function div two number
 * @stack: Stack list
 * @line_ctr: Line number
 */
void _div(stack_t **stack, unsigned int line_ctr)
{
	stack_t *current = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_ctr);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_ctr);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	div = current->next->n / current->n;
	current->next->n = div;
	_pop(stack, line_ctr);

}
void _mul(stack_t **stack, unsigned int line_ctr)
{
	stack_t *current = NULL;
	int mul = 0;
	
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_ctr);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	mul = current->next->n * current->n;
	_pop(stack, line_ctr);
	current->next->n = mul;	
}
