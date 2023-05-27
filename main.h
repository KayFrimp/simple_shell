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
#include <limits.h>

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
int spaces_check(char *lineptr);
int _strcmp(char *s1, char *s2);
void fxn_calls(char **argv, char **env, int i, char **av);
void exit_shell(char **argv);
int _isdigit(char *s);
int _atoi(char *s);
void print_env(char **argv, char **env);
void cmd_exec(char **argv, char **env, char *name, int count);
char *_strcat(char *dest, char *src);
char **get_cmdpath(char **env);

#endif /** MAIN_H **/
