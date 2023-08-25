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
