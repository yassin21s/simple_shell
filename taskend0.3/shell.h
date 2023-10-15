#ifndef SHIL_H
#define SHIL_H
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
extern char **environ;
char *read_cmd(void);
char * getpathcmd(char *cmd);
char *_getenv(char *varenv);
char **split_str(char *array);
void free_array(char **arg_spt);
int ececut_cmd(char **arg_spt, char **argv, int idx);
void print_error(char *name_sh, char *cmd, int index);
char *n_shell(int num);
void rev_str(char *str, int len);
char *_strdup(const char *str);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _putchar(char c);

#endif /*SHIL_H */
