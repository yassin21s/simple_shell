#include "shell.h"
/**
 * ececut_cmd - execute commad shell.
 * @arg_spt: argumants string.
 * @argv: argumants vecror.
 *
 * Return: commad execute.
 */
int ececut_cmd(char **arg_spt, char **argv)
{
		pid_t pid;
		int status;

		pid = fork();

		if (pid == 0)
		{
			if (execve(arg_spt[0], arg_spt, environ) == -1)
			{
				perror(argv[0]);
				free_array(arg_spt);
				exit(0);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			free_array(arg_spt);
		}
		return (WEXITSTATUS(status));
}
