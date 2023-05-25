#include "main.h"

/**
 * create_child - Fxn creates a child process to execute cmd
 * @name: Name of shell
 * @argv: Array of commands
 * @count: Program iteration count
 * @env: Environment List
 * Return: Null
 */
void create_child(char *name, char **argv, int count, char **env)
{
	pid_t child_pid, pid;
	int status;
	struct stat st;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:\n");
		free_array_exit(argv);
	}
	else if (child_pid == 0)
	{
		if (stat(argv[0], &st) == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				perror("Error with command\n");
				free_array_exit(argv);
			}
			/* exit(EXIT_SUCCESS); */
		}
		else
		{
			/* Run if command doesn't exist */
			_perror(name, count, argv);
			free_array(argv);
		}
	}
	else
	{
		pid = waitpid(child_pid, &status, 0);
		if (pid < 0)
		{
			free_array_exit(argv);
		}
		free_array(argv);
	}
}
