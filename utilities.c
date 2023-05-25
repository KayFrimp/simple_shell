#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: Char pointer variable
 *
 * Return: Always the length of a string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _memcpy - Copies n bytes from memory area src to dest
 * @src: char pointer to src memory area
 * @dest: char pointer to dest memory area
 * @n: number of bytes to copy from src
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strdup - duplicates string
 * @str: string to duplicate
 *
 * Return: Duplicated string or NUll on failure
 */
char *_strdup(char *str)
{
	char *dup_str;
	unsigned int len;

	len = _strlen(str);
	dup_str = malloc(sizeof(char) * (len + 1));
	if (dup_str == NULL)
		return (NULL);
	_memcpy(dup_str, str, len + 1);
	return (dup_str);
}

/**
 * _perror - prints error messahe
 * @name: Name of shell
 * @count: program iteration count
 * @argv: Array of commands.
 *
 * Return: Nothing.
 */
void _perror(char *name, int count, char **argv)
{
	char c;

	c = count + '0';
	write(2, name, _strlen(name));
	write(2, ": ", 2);
	write(2, &c, 1);
	write(2, ": ", 2);
	write(2, argv[0], _strlen(argv[0]));
	write(2, ": not found\n", 12);
}

/**
 * spaces_check - checks if the user input only spaces.
 * @lineptr: Pointer to array of input from user
 *
 * Return: 1 on success, 0 on failure
 */
int spaces_check(char *lineptr)
{
	int i = 0;

	lineptr[_strlen(lineptr) - 1] = '\0';
	while (lineptr[i] != '\0')
	{
		if (lineptr[i] != ' ')
			return (0);
		i++;

	}
	return (1);
}
