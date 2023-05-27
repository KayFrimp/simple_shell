#include "main.h"

/**
 * fxn_calls - Calls main shell functions
 * @argv: Array of user input in shell
 * @env: Environment path
 * @i: Shell iterator
 * @av: cmd line argument vector
 *
 * Return: Nothing
 */
void fxn_calls(char **argv, char **env, int i, char **av)
{
	if (argv != NULL)
	{
		if (_strcmp(argv[0], "exit") == 0)
			exit_shell(argv);
		else if (_strcmp(argv[0], "env") == 0)
			print_env(argv, env);
		else
		{
			/* Create child process to execute commands */
			create_child(av[0], argv, i, env);
		}
	}
	else
	{
		write(2, "Error: Issue with Arguments", 27);
		free_array(argv);
		exit(EXIT_FAILURE);
	}
}
