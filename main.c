#include"main.h"
/**
 * main - shell entry point.
 * Return: 0 always
 */
int main(void)
{
	char *lineptr, *cpy_lineptr, **argv;
	const char *delim = " \n";
	int count;

	while (1)
	{
		printf("#cisfun$ ");
		lineptr = get_input();
		/* Duplicate lineptr and get the number of tokens in count */
		cpy_lineptr = _strdup(lineptr);
		count = count_tokens(cpy_lineptr, delim);
		/* Call fxn to split lineptr to array of tokens */
		argv = split_strings(lineptr, delim, count);
		if (argv != NULL)
		{
			/* Create child process to execute commands */
			create_child(argv);
		}
		else
		{
			free_array(argv);
			free(lineptr);
		}
	}

	return (0);
}
