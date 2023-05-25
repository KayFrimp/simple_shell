#include"main.h"
/**
 * main - shell entry point.
 * Return: 0 always
 */
int main(void)
{
	char *lineptr, *cpy_lineptr, **argv;
	const char *delim = " \n";
	int count, i = 0;
	char **env = environ;

	while (1)
	{
		i++;
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
			create_child(argv, i, env);
		}
		else
		{
			write(2, "Error: Issue with Arguments", 27);
			free_array(argv);
			free(lineptr);
			exit(1);
		}
	}

	return (0);
}
