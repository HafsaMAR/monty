#include "monty.h"

/**
 * is_digit - function that convert string to number
 * @argument: string to convert
 * Return: number
*/
int is_digit(char *argument)
{
	if (*argument == '-' || *argument == '+')
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
	char *argument;

	argument = strtok(NULL, " \t\n");
	if (argument == NULL || !is_digit(argument))
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

/**
 * pint -  prints the value at the top of the stack
 * @stack: pointer to header of stack structure
 * @line_number: number line of the operation
*/

void pint(stack_t **stack, unsigned int line_number)
{

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: pointer to header of stack structure
 * @line_number: number line of the operation
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
(*stack) = (*stack)->next;
		free(temp);
}
