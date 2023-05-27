#include "main.h"

/**
 * get_cmdpath - Gets full cmd path from environment
 * @env: Environment
 * @pathvar: Path variable
 *
 * Return: directories in path or NULL
 */
char **get_cmdpath(char **env)
{
	char **env_cpy = env, *pathval = NULL, **pathvar = NULL, *delim = ":";
	int i = 0, count = 0;

	pathval = strtok(env_cpy[i], "=");
	while (env_cpy[i])
	{
		if (_strcmp(pathval, "PATH") == 0)
		{
			pathval = strtok(NULL, "\n");
			count = _strlen(pathval);
			pathvar = split_strings(pathval, delim, count);
			return (pathvar);
		}
		i++;
		pathval = strtok(env_cpy[i], "=");
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
	int len = 0, i, j = 0;

	while (*(dest + len) != '\0')
		len++;
	dest[len] = '/';
	len++;
	for (i = len; i > 0; i++)
	{
		if (*(src + j) == '\0')
		{
			*(dest + i) = '\0';
			break;
		}
		*(dest + i) = *(src + j);
		j++;
	}
	return (dest);
}
