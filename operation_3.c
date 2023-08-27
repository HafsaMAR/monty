#include "monty.h"

/**
 * mul - multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: pointer to header of stack structure
 * @line_number: number line of the operation
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int product;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = product;
	free(temp);
}

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: pointer to header of stack structure
 * @line_number: number line of the operation
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int remain;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	remain = (*stack)->next->n % (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = remain;
	free(temp);
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	c = (*stack)->n;
	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the stack to the left
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run (unused)
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)(line_number);

	if (!*stack || !(*stack)->next)
		return;

	temp = *stack;
	last = *stack;

	while (last->next)
		last = last->next;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
}
