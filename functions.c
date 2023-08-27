#include "monty.h"

/**
 * num_arg_check - checks the number of arguments is = 2
 * @ac: counter of argument
*/
void num_arg_check(int ac)
{
	/* check the number of arguments passed*/
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * file_check - checks the readability of a file
 * @av: string : name of file passed as argument
 * Return: file type opened
*/

FILE *file_check(char **av)
{
	FILE *input_file = fopen(av[1], "r");

	if (!input_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	return (input_file);
}

/**
 * get_operation - checks if the function is in the list of instructions
 * @operation_code: opcode the check
 * Return: A function pointer to the corresponding operation function,
 *         or NULL if no matching operation is found.
*/
void (*get_operation(char *operation_code))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t operations[] = {
		{"push", &push}, {"pall", &pall}, {"pint", &pint}, {"pop", &pop},
		{"swap", &swap}, {"nop", &nop}, {"add", &add}, {"sub", sub},
		{"div", &division}, {"mul", &mul}, {"mod", &mod}, {"stack", &stack},
		{"queue", &queue}, {"rotl", rotl}, {"rotr", rotr}, {"pchar", pchar},
		{"pstr", pstr}, {NULL, NULL}};
	for (i = 0; operations[i].opcode != NULL; i++)
	{
		if (strcmp(operation_code, operations[i].opcode) == 0)
		{
			return (operations[i].f);
		}
	}
	return (NULL);
}

/**
 * invalid_function - print error message if the instruction isn't found in the list
 * @line_num: line number of the command
 * @opcode: operation code
*/

void invalid_function(int line_num, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			line_num, opcode);
	exit(EXIT_FAILURE);
}

/**
 * tokenize_exec - function that tokenize the line and exeute its opcode
 * @info: structure containing the info
*/
void tokenize_exec(info_t *info)
{
	char *opcode;
	void (*function)(stack_t **stack, unsigned int line_number);

	opcode = strtok(info->line, " \t\n");
	if (!opcode || opcode[0] == '#')
		return;
	function = get_operation(opcode);
	if (function != NULL)
	{
		function(&info->stack, info->line_num);
	}
	else
		invalid_function(info->line_num, opcode);
}
