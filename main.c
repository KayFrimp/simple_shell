#include"main.h"
/**
 * main - shell entry point.
 * Return: 0 always
 */
int main(void)
{
	char *lineptr;

	printf("#cisfun$ ");
	lineptr = get_input();
	/* Duplicate lineptr and get the number of tokens in count */
	cpy_lineptr = strdup(lineptr);
	count = count_tokens(cpy_lineptr, delim);
	/* Call fxn to split lineptr to array of tokens */
	argv = split_strings(lineptr, delim, count);
	return (0);
}
