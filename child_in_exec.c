#include "main.h"

/**
 * cmd_exec - Child process executes command
 * @argv: Array of commands
 * @env: Environment variables
 * @name: Name of shell
 * @count: program iteration coint
 *
 * Return: Nothing
 */
void cmd_exec(char **argv, char **env, char *name, int count)
{
	struct stat st;
	char **pathvar = NULL, *cmdpath = NULL;
	int i = 0;

	if (stat(argv[0], &st) == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("Error with command\n");
			free_array_exit(argv);
		}
	}
	else
	{
		pathvar = get_cmdpath(env);
		while (pathvar[i])
		{
			cmdpath = _strcat(pathvar[i], argv[0]);
			i++;
			if (stat(cmdpath, &st) == 0)
			{
				if (execve(cmdpath, argv, env) == -1)
				{
					free_array(pathvar);
					free_array_exit(argv);
				}
				return;
			}
		}
		_perror(name, count, argv);
		free_array(pathvar);
		free_array(argv);
	}
}
