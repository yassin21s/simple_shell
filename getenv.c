#include "shell.h"
/**
 * _getenv - gets an environment variable.
 * @varenv: name of environment variable
 *
 * Return: Always 0 (Success)
 */
char *_getenv(const char *varenv)
{
	int i = 0;
	char *vartok, *valenv;

	while (environ[i])
	{
		vartok = strtok(environ[i], "=");
		if (strcmp(vartok, varenv) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	free(valenv);
	return (NULL);
}
