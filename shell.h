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
char * getpathcmd(char *cmd);
char *_getenv(const char *varenv);
char **split_str(char *array);
int _putchar(char c);

#endif /*SHIL_H */
