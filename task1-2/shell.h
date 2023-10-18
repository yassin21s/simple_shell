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
#define DELIMITERS " \t\n\r\a;&&"
extern char **environ;

char *read_cmd(void);
char **split_str(char *array);
void free_array(char **arg_spt);
char *_strdup(char *str);
int ececut_cmd(char **arg_spt, char **av);
void print_error(char *name_sh, char *cmd, int index);


#endif /*SHIL_H */
