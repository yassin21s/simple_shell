#include "shell.h"

/**
 * getpathcmd - gets an environment variable.
 * @cmd: input command string
 *
 * Return: reteun path command
 */
char *getpathcmd(char *cmd)
{
	char *path = _getenv("PATH");
	char *sl_path, *pathcmd;
	struct stat st;
	int i = 0;

	for (i = 0 ; cmd[i] ; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (strdup(cmd));
			return (NULL);
		}
	}
	sl_path = strtok(path, ":");
	while (sl_path)
	{
		pathcmd = malloc(strlen(sl_path) + strlen(cmd) + 2);
		strcpy(pathcmd, sl_path);
		strcat(pathcmd, "/");
		strcat(pathcmd, cmd);
		if (stat(pathcmd, &st) == 0)
			return (pathcmd);
		free(pathcmd);
		sl_path = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
