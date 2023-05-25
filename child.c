#include "main.h"

/**
 * create_child - Fxn creates a child process to execute cmd
 * @argv: Array of commands
 *
 * Return: Null
 */
void create_child(char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:\n");
		free_array(argv);
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
		wait(&status);
		free_array(argv);
	}
}
