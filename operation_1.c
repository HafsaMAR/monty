#include "monty.h"

int is_digit(char *argument)
{
	if (*argument == '-')
		argument++;
	while (*argument)
	{
		if (!isdigit(*argument))
			return (0);
		argument++;
	}
	return (1);
}

/**
 * push - pushes an element to the stack
 * @stack: pointer to head of list stack
 * @line_number: line number
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	int n;
	char *argument = strtok(NULL, " \t\n");

	if (!argument || !is_digit(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(argument);
	if (info.mode == MODE_QUEUE)
	add_node_end(stack, n);
	else
	add_node(stack, n);
}

/**
 * pall - prints all the elements of the list
 * @stack: pointer to header of stack structure
 * @line_number: number line of the operation
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

