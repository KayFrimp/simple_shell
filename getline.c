#include "main.h"

/**
 * get_input - Gets user input from cmd line
 *
 * Return: Address of buffer
 */
char *get_input(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t chars;

	chars = getline(&lineptr, &n, stdin);
	/* Failure to read a line and EOF condition check */
	if (chars == -1)
	{
		free(lineptr);
		if (isatty(0))
			write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}

	return (lineptr);
}
