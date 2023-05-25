#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_input(void);
char **split_strings(char *lineptr, const char *delim, int count);
int _strlen(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strdup(char *str);
int count_tokens(char *lineptr, const char *delim);

#endif /** MAIN_H **/
