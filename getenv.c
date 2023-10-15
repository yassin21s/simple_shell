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
	char *vartok, *token, *toke, *env;

	while (environ[i])
	{
		token = strdup(environ[i]);
		vartok = strtok(token, "=");
		if (strcmp(vartok, varenv) == 0)
			toke = strtok(NULL, "\n");
		env = strdup(toke);
		return (env);
		i++;
	}
	return (NULL);
}
