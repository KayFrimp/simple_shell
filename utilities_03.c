#include "main.h"

/**
 * get_cmdpath - Gets full cmd path from environment
 * @env: Environment
 *
 * Return: directories in path or NULL
 */
char **get_cmdpath(char **env)
{
	char *pathval = NULL, *cpy_pathval, **pathvar = NULL, *delim = ":";
	int i = 0, count = 0;

	pathval = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(pathval, "PATH") == 0)
		{
			pathval = strtok(NULL, "\n");
			cpy_pathval = _strdup(pathval);
			count = count_tokens(cpy_pathval, delim);
			pathvar = split_strings(pathval, delim, count);
			return (pathvar);
		}
		i++;
		pathval = strtok(env[i], "=");
	}
	return (NULL);
}

/**
 * *_strcat  - concatenates two strings
 * @dest: character pointer variable
 * @src: character pointer variable
 *
 * Return: Always a character pointer
 */
char *_strcat(char *dest, char *src)
{
	int len = 0, j = 0;

	while (dest[len])
		len++;
	dest[len] = '/';
	len++;
	while (src[j])
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	return (dest);
}
