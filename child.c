#include "main.h"

/**
 * create_child - Fxn creates a child process to execute cmd
 * @argv: Array of commands
 *
 * Return: Null
 */
void create_child(char **argv)
{
	pid_t child_pid, pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:\n");
		free_array(argv);
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error\n");
			free_array(argv);
			exit(1);
		}
	}
	else
	{
		pid = waitpid(child_pid, &status, 0);
		if (pid < 0)
		{
			free_array(argv);
			exit(1);
		}
	}
}
