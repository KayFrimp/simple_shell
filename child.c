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
	int status;
	pid_t child_pid, pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:\n");
		free_array_exit(argv);
	}
	else if (child_pid == 0)
	{
		cmd_exec(argv, env, name, count);
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
