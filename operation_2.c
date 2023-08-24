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
