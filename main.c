#include"main.h"
/**
 * main - shell entry point
 * @ac: argument count
 * @av: argument list.
 * Return: 0 always
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *lineptr, *cpy_lineptr, **argv;
	const char *delim = " \n\t\0";
	int count, i = 0;
	char **env = environ;

	while (1)
	{
		i++;
		if (isatty(0))
			write(1, "#cisfun$ ", 10);
		lineptr = get_input();
		if (*lineptr == '\n' || spaces_check(lineptr))
			free(lineptr);
		else
		{
			/* Duplicate lineptr and get the number of tokens in count */
			cpy_lineptr = _strdup(lineptr);
			count = count_tokens(cpy_lineptr, delim);
			/* Call fxn to split lineptr to array of tokens */
			argv = split_strings(lineptr, delim, count);
			if (argv != NULL)
			{
				/* Create child process to execute commands */
				create_child(av[0], argv, i, env);
			}
			else
			{
				write(2, "Error: Issue with Arguments", 27);
				free_array(argv);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}
