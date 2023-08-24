#include "monty.h"

/**
 * stack - sets the mode to STACK
 * @stack: pointer to head of the linked list
 * @line_number: line number of the command
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	info.mode = MODE_STACK;
}

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	info.mode = MODE_QUEUE;
}
