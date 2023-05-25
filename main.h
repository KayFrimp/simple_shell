#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *get_input(void);
char **split_strings(char *lineptr, const char *delim, int count);
int _strlen(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strdup(char *str);
int count_tokens(char *lineptr, const char *delim);
void free_array(char **buffer);
void free_array_exit(char **buffer);
void create_child(char *name, char **argv, int count, char **env);
void _perror(char *name, int count, char **argv);

#endif /** MAIN_H **/
