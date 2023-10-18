#include "shell.h"
/**
 * ececut_cmd - execute commad shell.
 * @arg_spt: argumants string.
 * @argv: argumants vector.
 *
 * Return: return status.
 */
int ececut_cmd(char **arg_spt, char **argv)
{
		pid_t child;
		int status;

		child = fork();

		if (child == 0)
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
			waitpid(child, &status, 0);
			free_array(arg_spt);
		}
		return (WEXITSTATUS(status));
}
