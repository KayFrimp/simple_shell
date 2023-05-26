#include "main.h"

/**
 * _atoi - converts string to integer
 * @s: character pointer variable
 *
 * Return: Retrun number or 0 if there is none
 */
int _atoi(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;
	return (0);
}

/**
 * _strcmp - compares two strings
 * @s1: Character pointer variable
 * @s2: Character pointer variable
 *
 * Return: 0 for equal, 1 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}


/**
 * exit_shell - Exits the shell
 * @argv: Array of commands
 *
 * Return: NOthing
 */
void exit_shell(char **argv)
{
	int status = 0;

	if (argv != NULL)
	{
		if (argv[0] != NULL)
		{
			status = _atoi(argv[0]);
			free_array(argv);
			exit(status);
		}
	}
}
