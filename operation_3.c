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
	(*stack)->next->n = remain;
	free(temp);
}
