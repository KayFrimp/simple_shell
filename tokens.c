#include "main.h"
/**
 * split_strings - Returns array of tokens
 * @lineptr: pointer to user input
 * @delim: delimiters
 * @count: number of tokens
 *
 * Return: Array of tokens or Null on failure
 */
char **split_strings(char *lineptr, const char *delim, int count)
{
	char **tokens = NULL, *token;
	unsigned int i;

	if (lineptr == NULL)
		return (NULL);
	/* Allocate memory to hold tokens */
	tokens = malloc(sizeof(char *) * (count + 1));
	if (tokens == NULL)
	{
		free(lineptr);
		return (NULL);
	}
	/* Get array of tokens with strtok lib */
	token = strtok(lineptr, delim);
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free_array(tokens);
			free(lineptr);
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	/* free(token); */
	free(lineptr);
	return (tokens);
}
