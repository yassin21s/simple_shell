#include "shell.h"
/**
 * _getenv - gets an environment variable.
 * @varenv: name of environment variable
 *
 * Return: Always 0 (Success)
 */
char *_getenv(char *varenv)
{
	int i = 0;
	char *vartok, *token, *toke, *env;

	while (environ[i])
	{
		token = _strdup(environ[i]);
		vartok = strtok(token, "=");
		if (_strcmp(vartok, varenv) == 0)
		{
			toke = strtok(NULL, "\n");
		env = _strdup(toke);
		free(token);
		return (env);
		}
		free(token), token = NULL;
		i++;
	}
	return (NULL);
}
