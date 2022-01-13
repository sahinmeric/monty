#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE /*for getline error*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_s - global and its funcs
 * @fptr: File pointer for communication between file and program
 * @line: Line to getline
 *
 * Description: To handle the file and getline
 */
typedef struct glob_s
{
	FILE *fptr;
	char *line;
} glob_t;

extern glob_t global;
extern int value; /*just one global variable allowed. remove this*/
void read_op(char *argv);
int get_op(stack_t **stack, char *line, char *tkn, int line_count);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int n);
void _pint(stack_t **stack, unsigned int line_ctr);
void _pop(stack_t **stack, unsigned int line_ctr);
void _swap(stack_t **stack, unsigned int line_ctr);
void _add(stack_t **stack, unsigned int line_ctr);
void _nop(stack_t **stack, unsigned int line_ctr);
/*aux*/
int _isdigit(char *c);
void free_dlistint(stack_t *stack);
void cleanStack(stack_t **stack);

/*error handling*/
void push_error(FILE *fd, char *line, stack_t *stack, int line_ctr);
void ins_error(FILE *fd, char *line, stack_t *stack, char *line_ctr, int item);

#endif /*MONTY_H*/
