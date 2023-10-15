#include "shell.h"
/**
 * ececut_cmd - execute commad shell.
 * @arg_spt: argumants string.
 * @argv: argumants vecror.
 * @idx: the counter int
 *
 * Return: commad execute.
 */
int ececut_cmd(char **arg_spt, char **argv, int idx)
{
		pid_t pid;
		int status;
		char *pathcmd;

		pathcmd = getpathcmd(arg_spt[0]);
		if (!pathcmd)
		{
			print_error(argv[0], arg_spt[0], idx);
			free_array(arg_spt);
			return (0);
		}
		pid = fork();
		if (pid == 0)
		{
			if (execve(pathcmd, arg_spt, environ) == -1)
			{
				perror(arg_spt[0]);
				free(pathcmd), pathcmd = NULL;
				free_array(arg_spt);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			free(pathcmd), pathcmd = NULL;
			free_array(arg_spt);
		}
		return (WEXITSTATUS(status));
}
