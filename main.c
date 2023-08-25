#include "monty.h"

info_t info = {0};

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
	while (fgets(info.line, sizeof(info.line), input_file))
	{
		info.line_num++;
		tokenize_exec(&info);
	}

	/* open the file and check it readability*/

	/* tokenize each line and execute the function*/

	fclose(input_file);
	free_list(info.stack);
	return (0);
}
