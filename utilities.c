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
 * free_array - Frees memory allocated to array
 * @buffer: array of pointers
 *
 * Return: Nothing
 */
void free_array(char **buffer)
{
	unsigned int i = 0;

	if (buffer == NULL)
		return;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
