#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to header of stack structure
 * @line_number: number line of the operation
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *element1, *element2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);

		exit(EXIT_FAILURE);
	}
	element1 = *stack;
	element2 = (*stack)->next;
	element1->prev = element2;
	element1->next = element2->next;
	if (element2->next)
	{
		element2->next->prev = element1;
	}
	element2->next = element1;
	element2->prev = NULL;
	*stack = element2;
}

/**
 * add -  adds the top two elements of the stack.
 * @stack: pointer to header of stack structure
 * @line_number: number line of the operation
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;
	free(temp);
}

/**
 * nop - doesn’t do anything.
 * @stack: pointer to header of stack structure
 * @line_number: number line of the operation
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack.
 * @stack: pointer to header of stack structure
 * @line_number: number line of the operation
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int difference;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	difference = (*stack)->next->n - (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = difference;
	free(temp);
}

/**
 * division - divides the second top element of the stack by
 * the top element of the stack.
 * @stack: pointer to header of stack structure
 * @line_number: number line of the operation
*/
void division(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int quot;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quot = (*stack)->next->n / (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = quot;
	free(temp);
}
