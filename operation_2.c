#include "monty.h"

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

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (*stack == NULL || !(*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	stack = (*stack)->next;
	(*stack)->n = sum;
	free(temp);
}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int difference;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	diff = (*stack)->next->n - (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = diff;
	free(temp);
}
