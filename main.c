#include "monty.h"

info_t info = {0};

void num_arg_check(int ac)
{
	/* check the number of arguments passed*/
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

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

/*{"push", &push}, {"pall", &pall}, ,  , , , {"sub", sub}, {"div", &division}, {"mul", &mul}, {"rotl", &rotl}, {"rotr", &rotr}, {"stack", &stack}, {"queue", &queue}, {"pstr", &pstr}, {"pchar", &pchar}, {"mod", &mod}, {NULL, NULL}};*/
void (*get_operation(char *operation_code))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t operations[] = {
		{"push", &push}, {"pall", &pall}, {"pint", &pint}, {"pop", &pop}, {"swap", &swap}, {"nop", &nop}, {"add", &add}, {"sub", sub}, {"div", &division}, {"mul", &mul}, {"mod", &mod}, {"stack", &stack}, {"queue", &queue}, {NULL, NULL}};
	for (i = 0; operations[i].opcode != NULL; i++)
	{
		if (strcmp(operation_code, operations[i].opcode) == 0)
		{
			return (operations[i].f);
		}
	}
	return (NULL);
}
void invalid_function(int line_num, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			line_num, opcode);
	exit(EXIT_FAILURE);
}
void tokenize_exec(FILE *input_file, info_t info)
{
	char *opcode, *comment_pos;
	void (*function)(stack_t **stack, unsigned int line_number);

	/* intialization of the structure*/

	while (fgets(info.line, sizeof(info.line), input_file))
	{
		info.line_num++;
		comment_pos = strstr(info.line, " #");
		if (comment_pos != NULL)
		{
			*comment_pos = '\n';
		}
		opcode = strtok(info.line, " \t\n");
		if (!opcode || opcode[0] == '#')
			return;
		function = get_operation(opcode);
		if (function != NULL)
			function(&info.stack, info.line_num);
		else
			invalid_function(info.line_num, opcode);
	}
}

/**
 * main - entry point
 * @ac: number of argument
 * @av: pointer to array of string arguments passed to the executable file
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	FILE *input_file;
	info_t info = {0};

	num_arg_check(ac);
	input_file = file_check(av);
	tokenize_exec(input_file, info);

	/* open the file and check it readability*/

	/* tokenize each line and execute the function*/

	fclose(input_file);
	free_list(info.stack);
	free_info(info);
	return (0);
}
