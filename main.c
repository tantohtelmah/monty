#include "monty.h"

global_t variables_global;

/**
 * free_variables_global - frees the global variables
 * Return: no return
 */
void free_variables_global(void)
{
	free_dlistint(variables_global.head);
	free(variables_global.buffer);
	fclose(variables_global.file);
}

/**
 * start_variables_global - initializes the global variables
 * @file: file descriptor
 * Return: no return
 */
void start_variables_global(FILE *file)
{
	variables_global.lifo = 1;
	variables_global.cont = 1;
	variables_global.arg = NULL;
	variables_global.head = NULL;
	variables_global.file = file;
	variables_global.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *file;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (file);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *file;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	file = check_input(argc, argv);
	start_variables_global(file);
	nlines = getline(&variables_global.buffer, &size, file);
	while (nlines != -1)
	{
		lines[0] = _strtoky(variables_global.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", variables_global.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_variables_global();
				exit(EXIT_FAILURE);
			}
			variables_global.arg = _strtoky(NULL, " \t\n");
			f(&variables_global.head, variables_global.cont);
		}
		nlines = getline(&variables_global.buffer, &size, file);
		variables_global.cont++;
	}

	free_variables_global();

	return (0);
}
