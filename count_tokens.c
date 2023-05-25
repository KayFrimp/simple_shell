#include "main.h"
/**
 * count_tokens - Function counts number of string tokens
 * @lineptr: pointer to user input
 * @delim: delimiter
 *
 * Return: number of tokens
 */
int count_tokens(char *lineptr, const char *delim)
{
	char *token;
	int count = 0;

	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(lineptr);
	return (count);
}
