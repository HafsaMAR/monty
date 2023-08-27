#include "monty.h"

/**
 * add_node - add node a the begining of the doubly linked list
 * @h: pointer to head of list
 * @n: date to add
 * Return: pointer to new node
*/
stack_t *add_node(stack_t **h, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = *h;
	new_node->prev = NULL;
	if (*h != NULL)
		(*h)->prev = new_node;
	*h = new_node;
	return (*h);
}

/**
 * add_node_end - add node a the end of the doubly linked list
 * @h: pointer to head of list
 * @n: date to add
 * Return: pointer to new node
*/
stack_t *add_node_end(stack_t **h, int n)
{
	stack_t *new_node;
	stack_t *end_node = *h;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;

	if (*h == NULL)
	{
		new_node->prev = NULL;
		*h = new_node;
		return (new_node);
	}
	while (end_node->next)
	{
		end_node = end_node->next;
	}
	end_node->next = new_node;
	new_node->prev = end_node;
	return (new_node);
}

/**
 * free_list - free the doubly linked list stack
 * @h: pointer to head of the stack
*/
void free_list(stack_t *h)
{
	stack_t *node;

	while (h != NULL)
	{
		node = h;
		h = h->next;
		free(node);
	}
}

void free_info(info_t info)
{
	if (info.stack)
	{
		free_list(info.stack);
	}
}

/**
 * rotr - Rotates the stack to the right
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run (unused)
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	temp->prev = last;
	last->next = temp;
	*stack = last;
}
