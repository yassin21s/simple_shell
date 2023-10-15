#include "shell.h"
/**
 * getpathcmd - gets an environment variable.
 * @cmd: input command string
 *
 * Return: reteun path command
 */
char *getpathcmd(char *cmd)
{
	char *path, *sl_path, *pathcmd;
	struct stat st;
	int i = 0;

	for (i = 0 ; cmd[i] ; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);
	sl_path = strtok(path, ":");
	while (sl_path)
	{
		pathcmd = malloc(_strlen(sl_path) + _strlen(cmd) + 2);
		if (pathcmd)
		{
			_strcpy(pathcmd, sl_path);
			_strcat(pathcmd, "/");
			_strcat(pathcmd, cmd);
			if (stat(pathcmd, &st) == 0)
			{
				free(path);
				return (pathcmd);
			}
			free(pathcmd), pathcmd = NULL;
			sl_path = strtok(NULL, ":");
		}
	}
		free(path);
		return (NULL);
}
