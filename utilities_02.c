#include "main.h"

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
	int num, status = 0;

	if (argv[0] != NULL)
	{
		num = _isdigit(argv[0]);
		if (!num)
			status = 2;
		free_array(argv);
		exit(status);
	}
}

/**
 * _isdigit - checks if string is a number
 * @s: pointer to char
 *
 * Return: 1 if s points to a number and 0 if otherwise
 */
int _isdigit(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
